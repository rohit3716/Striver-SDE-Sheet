class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<int> nums(m+n);
        int j = 0;
        for( int i = 0; i < m; i++) {
            nums[j++] = nums1[i];
        }
        for( int i = 0; i < n; i++) {
            nums[j++] = nums2[i];
        }

        sort(nums.begin(), nums.end() );
        int mid = (m+n)/2;
        
        if( (m+n) % 2 == 0 ) {
            double ans = (double)(double)((nums[mid]+nums[mid-1])/2.0);
            return ans;
        }
        else{
            return nums[mid];
        }

    }
};