class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        sort(potions.begin(), potions.end());
        for (int s : spells) {
            long long minPotion = (success + s - 1) / s; // potion >= success/spell[i]
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            int successfulCount = potions.end() - it;
            result.push_back(successfulCount);
        }
        return result;
    }
};