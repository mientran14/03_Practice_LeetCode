class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> nextGreater;
        stack<int> st_dcr;

        for(int n : nums2) {
            while(!st_dcr.empty() && st_dcr.top() < n) {
                nextGreater[st_dcr.top()] = n;
                st_dcr.pop();
            }
            st_dcr.push(n);
        }

        while(!st_dcr.empty()) {
            nextGreater[st_dcr.top()] = -1;
            st_drc.pop();
        }

        for(int n : nums1) {
            result.push_back(nextGreater[n]);
        }
    
        return result;
    }
};
