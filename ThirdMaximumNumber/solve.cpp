class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        // for (int num : nums) {
        //     if (num > first) {
        //         third = second;
        //         second = first;
        //         first = num;
        //     } else if (num > second && num < first) {
        //         third = second;
        //         second = num;
        //     } else if (num > third && num < second) {
        //         third = num;
        //     }
        // }
        // return third == LONG_MIN ? first : third;


        // sort(nums.begin(), nums.end(), std::greater<int>());
        // int distiCount = 1;
        // int thirdMax = nums[0];
        // for (int n : nums) {
        //     if (distiCount < 3) {
        //         if (n < thirdMax) {
        //             thirdMax = n; 
        //             ++distiCount;
        //         }
        //     }
        // }
        // if (distiCount < 3) {
        //     return nums[0];
        // }
        // return thirdMax;


        set<int> disti(nums.begin(), nums.end());
        if (disti.size() < 3) {
            return *disti.rbegin(); 
        }
        auto it = disti.rbegin();
        std::advance(it, 2);
        return *it;
    }
};