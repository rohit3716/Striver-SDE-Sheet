class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long int num = 1;
        int flag = 0;
        for( int i = 0; i < n; i++) {
            
            if( nums[i] == 0 ) {
                flag++;
                continue;
            }    
            num *= nums[i];
        }

        if( flag >= 2) {
            for( int i = 0; i < n; i++) {
            nums[i] = 0;    
            }
        }
        else if(flag == 1){
            for( int i = 0; i < n; i++) {
            if(nums[i] == 0 ){
                nums[i] = num;
            }
            else{
                nums[i] = 0;
            }
            }
        }
        else {
            for( int i = 0; i < n; i++) {
                nums[i] = num/nums[i];
            }
        }
        return nums;
    }
    
};