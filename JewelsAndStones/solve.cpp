class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jew;
        for(char j : jewels) jew.insert(j);

        int count = 0;
        for(char s : stones) {
            if(jew.find(s) != jew.end()) count++;
        }
        return count++;
    }
};
