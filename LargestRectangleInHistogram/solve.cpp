class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Time Limit Exceeded 91 / 99 testcases passed
        // Need to fix
        function<int(int, int)> calArea = [&](int start, int end) -> int {
            if (start > end) return 0;

            int minindx = start;
            for (int i = start; i <= end; i++) {
                if (heights[i] < heights[minindx]) minindx = i;
            }

            return max({
                heights[minindx] * (end - start + 1),
                calArea(start, minindx - 1),
                calArea(minindx + 1, end)
            });
        };

        return calArea(0, heights.size() - 1);
    }
};