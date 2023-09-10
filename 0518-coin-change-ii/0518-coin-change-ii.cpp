class Solution {
public:
    int solve( int ind, int target, vector<int>& coins, vector<vector<long>>& dp) {
        if( ind == 0 ) {
            return (target % coins[0] == 0);
        }

        if( dp[ind][target] != -1 ) return dp[ind][target];

        long notTake = solve( ind-1, target, coins, dp);
        long take = 0; 
        if( coins[ind] <= target ) {
            take = solve(ind, target-coins[ind], coins, dp);
        }
        return dp[ind][target] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount+1, -1));
        return solve( n-1, amount, coins, dp);
    }
};