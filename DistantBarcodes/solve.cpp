class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;
        for (int b : barcodes) freq[b]++;

        vector<pair<int, int>> sortedFreq;
        for (auto& [b, count] : freq) {
            sortedFreq.push_back({count, b});
        }
        sort(sortedFreq.rbegin(), sortedFreq.rend()); // giá trị xuất hiện nhiều nhất sẽ được ưu tiên xử lý trước

        vector<int> result(barcodes.size());
        int idx = 0;
        for (auto& [count, b] : sortedFreq) {
            for (int i = 0; i < count; i++) {
                result[idx] = b;
                idx += 2;
                if (idx >= barcodes.size()) idx = 1;
            }
        }

        return result;
    }
};