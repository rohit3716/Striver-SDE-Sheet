class Solution {
public:

    bool isSafe( int row, int col, vector<vector<char>>& board, char val){
        for( int i = 0; i < 9; i++) {
            //row check 
            if( board[row][i] == val ) {
                return false;
            }
            //col check
            if( board[i][col] == val ) {
                return false;
            }
            //3*3 matrix check
            if( board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == val) {
                return false;
            }
           
        }
        return true;
    }

    bool solve(vector<vector<char>>& board ){
        int n = board[0].size();
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++) {
                if( board[i][j] == '.') {
                    for( char c = '1'; c <= '9'; c++) {
                        if( isSafe( i, j, board, c)) {
                            board[i][j] = c;

                            if( solve(board) == true ) {
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};