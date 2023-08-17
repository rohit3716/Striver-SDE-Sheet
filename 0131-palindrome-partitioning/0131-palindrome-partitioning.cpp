class Solution {
public:
    bool isPallindrome( string s, int st, int e)  {
        while( st <= e ) {
            if( s[st++] != s[e--]) return false;
        }
        return true;
    }
    void solve( int index, string s, vector<vector<string>>& ans, vector<string>& ds) {
        if( index == s.size()){
            ans.push_back( ds );
            return;
        }

        for( int i = index; i < s.size(); i++) {
            if( isPallindrome( s, index, i)) {
                ds.push_back( s.substr( index, i-index+1));
                solve( i+1, s, ans, ds);
                ds.pop_back();
            }
        }
    }
   
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0, s, ans, ds );

        return ans;
    }
};