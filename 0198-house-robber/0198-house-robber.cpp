class Solution {
public:
    int solve( vector<int>& dp, int ind, vector<int>& nums) {
        if( ind == 0 ) return nums[0];
        if( ind < 0) return 0;

        if( dp[ind] != -1 ) return dp[ind];

        int pick = nums[ind] + solve( dp, ind-2, nums);
        int notPick = 0 + solve( dp, ind-1, nums);

        dp[ind] = max( pick, notPick);

        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp( n, -1);
        return solve( dp, n-1, nums);
    }
};