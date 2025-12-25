class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = 0;
        for (int a : apple) {
            totalApple += a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int countbox = 0;
        for (int c : capacity) {
            totalApple -= c;
            countbox++;
            if (totalApple <= 0) break;
        }

        return countbox;
    }
};
