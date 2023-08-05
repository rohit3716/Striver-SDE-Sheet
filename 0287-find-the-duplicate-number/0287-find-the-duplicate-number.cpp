class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+1, 0);

        for( int i = 0; i < n; i++) {
            if(count[nums[i]] == 0 ){
                count[nums[i]] += 1;
            }
            else{
                return nums[i];
            }
        }

        return 0;
    }
};