class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // vector<int> even;
        // vector<int> odd;
        // for (int n : nums) {
        //     if (n%2 == 0) even.push_back(n);
        //     else odd.push_back(n);
        // }
        // even.insert(even.end(), odd.begin(), odd.end());
        // return even;


        // int left = 0, right = nums.size() - 1;
        // while (left < right) {
        //     if (nums[left] % 2 == 0) {
        //         left++;
        //     }
        //     else if (nums[right] % 2 != 0) {
        //         right--;
        //     }
        //     else {
        //         swap(nums[left], nums[right]);
        //         left++;
        //         right--;
        //     }
        // }
        // return nums;

        int indexEven = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]%2 == 0) swap(nums[indexEven++], nums[i]);
        }
        return nums;
    }
};