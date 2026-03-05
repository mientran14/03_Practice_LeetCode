class Solution {
public:
    int minOperations(string s) {
        int count1 = 0, count2 = 0;

        for (int i = 0; i < s.size(); i++) {
            count1 += (s[i] != (i % 2 == 0 ? '0' : '1'));   // 010101...
            count2 += (s[i] != (i % 2 == 0 ? '1' : '0'));   // 101010...
        }

        return min(count1, count2);
    }
};