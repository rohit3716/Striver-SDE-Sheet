class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> umap;
        int n = nums2.size();
        for( int i = n-1; i >= 0; i-- ) {
            int element = nums2[i];
            while( !st.empty() && st.top() <= element) {
                st.pop();
            } 
            int res = (st.empty()) ? -1 : st.top();
            umap.insert({element, res});
            st.push(element);           
        }

        vector<int> ans;
        for( auto x:nums1 ) {
            ans.push_back(umap[x]);
        }
        return ans;
    }
};