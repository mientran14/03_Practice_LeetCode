class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curAlt = 0, maxAlt = 0;

        for (int g : gain) {
            curAlt += g;
            maxAlt = max(maxAlt, curAlt);
        }

        return maxAlt;
    }
};