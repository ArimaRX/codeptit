/*
Jump game
Given an positive integer N and a list of N integers A[]. Each element in the array denotes the maximum length of jump you can cover. Find out if you can make it to the last index if you start at the first index of the list.


Example 1:

Input:
N = 6
A[] = {1, 2, 0, 3, 0, 0}
Output:
1
Explanation:
Jump 1 step from first index to
second index. Then jump 2 steps to reach
4th index, and now jump 2 steps to reach
the end.
Example 2:

Input:
N = 3
A[] =  {1, 0, 2}
Output:
0
Explanation:
You can't reach the end of the array.
Constraints:
1 <= N <= 105
1 <= A[i] <= 105
*/
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int canReach(int A[], int N) {
        int duong = 0;
        for (int i = 0; i < N; i++) {
            if (duong < i) return 0;
            duong = max(duong, A[i] + i);
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        int A[1000];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.canReach(A, N) << endl;
    }
    return 0;
}  // } Driver Code Ends