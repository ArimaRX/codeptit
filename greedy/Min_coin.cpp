/*
Min Coin
Given a list of coins of distinct denominations and total amount of money. Find the minimum number of coins required to make up that amount. Output -1 if that money cannot be made up using given coins.
You may assume that there are infinite numbers of coins of each type.


Example 1:

Input: arr = [1, 2, 5], amount = 11
Output: 3
Explanation: 2*5 + 1 = 11. So taking 2
denominations of 5 and 1 denomination of
1, one can make 11.
Example 2:

Input: arr = [2, 6], amount = 7
Output: -1
Explanation: Not possible to make 7 using
denominations 2 and 6.
Contstraints:
1 <= number of distinct denominations <= 100
1 <= amount <= 10000
*/
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int MinCoin(vector<int>nums, int amount)
    {
        vector<int> dp = {};
        dp.resize(amount + 1);

        for (int i = 0; i <= amount; i++) {
            dp[i] = -1;
        }
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i >= nums[j])
                {
                    if (dp[i - nums[j]] != -1)
                    {
                        if (dp[i] == -1)
                        {
                            dp[i] = 1 + dp[i - nums[j]];
                        }
                        else
                        {
                            dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
                        }
                    }
                }
            }

        }

        return dp[amount];
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, amount;
        cin >> n >> amount;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.MinCoin(nums, amount);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends