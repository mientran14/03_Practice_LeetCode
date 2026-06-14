class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = 0, sumBob = 0;

        for (int a : aliceSizes) sumAlice += a;
        for (int b : bobSizes) sumBob += b;

        int delta = (sumAlice - sumBob)/2;

        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

        for (int a : aliceSizes) {
            int b = a - delta;
            if (bobSet.count(b)) return {a, b};
        }

        return {};
    }
};