class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandy = *max_element(candies.begin(), candies.end());
        for (int c : candies) {
            result.push_back(c >= maxCandy - extraCandies);
        }
        return result;
    }
};