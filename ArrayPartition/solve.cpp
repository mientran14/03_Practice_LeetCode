class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        // Các số ở vị trí chẵn sau khi đã sort mảng sẽ là các số nhỏ hơn trong mỗi cặp
        for(int i = 0; i < nums.size(); i+=2) {
            result += nums[i];
        }
        return result;
    }
};
