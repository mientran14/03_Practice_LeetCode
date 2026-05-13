class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxS = 0;

        while (left < right) {
            int s = min(height[left], height[right]) * (right-left);
            maxS = max(maxS, s);
            if (height[left] < height[right]) left++;
            else right--;
        }

        return maxS;
    }
};