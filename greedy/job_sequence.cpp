/*
Job Sequencing Problem
Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500

bonus example
Input: Four Jobs with following deadlines and profits
JobID Deadline Profit
   a      4      20
   b      1      10
   c      1      40
   d      1      30
Output: Following is maximum profit sequence of jobs:
       c, a

Input: Five Jobs with following deadlines and profits
JobID Deadline Profit
   a     2       100
   b     1       19
   c     2       27
   d     1       25
   e     3       15
Output: Following is maximum profit sequence of jobs:
       c, a, e
giải thích:
có thể lấy được cả a và c vì tất cả công việc chỉ tốn 1 unit time với thời gian khởi điểm được
 tùy chọn => với deadline 2 thì chỉ có tối đa 1 công việc trước đó, 3 thì tối đa 2 công việc 
 trước đó, 1 chỉ được phép xếp đầu ,...
*/
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job 
struct Job
{
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    static bool mycomp(Job a, Job b) {
        if (a.dead < b.dead)
            return true;

        if (a.dead == b.dead and a.profit > b.profit)
            return true;

        return false;

    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<int> ans(2, 0);
        int currtime = 0;
        priority_queue <int, vector<int>, greater<int> > pq;
        sort(arr, arr + n, mycomp);

        for (int i = 0; i < n; i++) {
            Job j = arr[i];

            if (j.dead > currtime) {
                ans[0]++;
                ans[1] += j.profit;
                currtime++;
                pq.push(j.profit);
            }
            else if (pq.size() and pq.top() < j.profit) {
                ans[1] -= pq.top();
                ans[1] += j.profit;
                pq.pop();
                pq.push(j.profit);
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
// Driver program to test methods 
int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--) {
        int n;

        //size of array
        cin >> n;
        Job arr[1000];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}


// } Driver Code Ends