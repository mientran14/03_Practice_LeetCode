class Solution {
public:
    int minimumPushes(string word) {
        // 8 chữ đầu (1->8): phân bố cho các phím 2 -> 9: lần 1
        // 8 chữ tiếp (9->16): phân bố cho các phím 2 -> 9: lần 2
        // 8 chữ tiếp (17->24): phân bố cho các phím 2 -> 9: lần 3
        // Các chữ còn lại (25, 26): phân bố cho các phím 2, 3: lần 4

        int result = 0;
        for (int i = 0; i < word.size(); ++i) {
            result += (i / 8) + 1;
        }
        return result;
    }
};