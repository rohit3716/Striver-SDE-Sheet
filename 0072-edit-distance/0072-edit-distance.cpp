class Solution {
public:

    int solve( int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if( i == 0 ) return j;
        if( j == 0 ) return i;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( word1[i-1] == word2[j-1] )
            return dp[i][j] =  0 + solve( i-1, j-1, word1, word2, dp);
        else
            return dp[i][j] = 1 + min(solve( i, j-1, word1, word2, dp), min( solve( i-1, j, word1, word2, dp),
            solve( i-1, j-1, word1, word2, dp)));
        
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        //base case 
        for( int j = 0; j <= m; j++) dp[0][j] = j;
        for( int i = 0; i <= n; i++) dp[i][0] = i;

        for( int i = 1; i <= n; i++) {
            for( int j = 1; j <= m; j++) {
                if( word1[i-1] == word2[j-1] )
                    dp[i][j] =  0 + dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i][j-1], min( dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};