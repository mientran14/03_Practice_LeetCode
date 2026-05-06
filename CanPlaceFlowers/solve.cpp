class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flwplant = 0;
        int count0adj = 1; // Initialize 1 for the left boundary
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                count0adj++;
            } else {
                flwplant += (count0adj - 1) / 2;
                count0adj = 0;
            }
        }
        // right boundary
        flwplant += count0adj / 2;

        return flwplant >= n;
    }
};