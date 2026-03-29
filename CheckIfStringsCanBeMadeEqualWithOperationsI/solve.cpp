class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        array<int, 26> evenCount1 = {}, oddCount1 = {};
        array<int, 26> evenCount2 = {}, oddCount2 = {};

        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0) {
                evenCount1[s1[i] - 'a']++;
                evenCount2[s2[i] - 'a']++;
            } else {
                oddCount1[s1[i] - 'a']++;
                oddCount2[s2[i] - 'a']++;
            }
        }
        
        return evenCount1 == evenCount2 && oddCount1 == oddCount2;
    }
};