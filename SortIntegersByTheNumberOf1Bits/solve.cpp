class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> bitCount;
        for (int num : arr) {
            int count = 0, n = num;
            while (n > 0) {
                count += (n & 1);
                n >>= 1;
            }
            bitCount[num] = count;
        }

        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (bitCount[a] == bitCount[b]) {
                return a < b;
            }
            return bitCount[a] < bitCount[b];
        });

        return arr;
    }
};