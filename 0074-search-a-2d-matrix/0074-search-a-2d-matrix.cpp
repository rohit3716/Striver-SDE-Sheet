class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m*n-1;

        if( !m ){
            return false;
        }

        while( low <= high ){
            int mid = low + ( high - low )/2;

            if( matrix[mid/n][mid%n]  < target ) {
                low = mid+1;
            }
            else if( matrix[mid/n][mid%n] > target ){
                high = mid-1;
            }
            else{
                return true;
            }
        }
        return false;

    }
};