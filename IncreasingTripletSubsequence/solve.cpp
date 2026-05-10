class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int val1 = INT_MAX, val2 = INT_MAX;
        for (int n : nums) {
            if(n <= val1) val1 = n;
            else if(n <= val2) val2 = n;
            else return true;
        }
        return false;
    }
};