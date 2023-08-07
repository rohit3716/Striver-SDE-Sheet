class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mapp;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int moreNeed = target-num;

            if( mapp.find(moreNeed) != mapp.end()){
                return {mapp[moreNeed], i};
            }
            mapp[num] = i;
        }
        return {-1, -1};
    }
};