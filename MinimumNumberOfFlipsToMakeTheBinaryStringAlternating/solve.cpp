class Solution {
public:
    int minFlips(string s) {
        int result = INT_MAX;
        int len = s.size();

        int count1 = 0, count2 = 0;
        for (int i = 0; i < s.size(); i++) {
            count1 += (s[i] != (i % 2 == 0 ? '0' : '1'));   // 010101...
            count2 += (s[i] != (i % 2 == 0 ? '1' : '0'));   // 101010...
        }

        result = min(count1, count2);

        string newS = s + s;
        for (int i = len; i < 2*len; i++) {
            if (newS[i - len] != ((i - len) % 2 == 0 ? '0' : '1')) count1--;
            if (newS[i - len] != ((i - len) % 2 == 0 ? '1' : '0')) count2--;

            if (newS[i] != (i % 2 == 0 ? '0' : '1')) count1++;
            if (newS[i] != (i % 2 == 0 ? '1' : '0')) count2++;

            result = min(result, min(count1, count2));
        }
        return result;
    }
};