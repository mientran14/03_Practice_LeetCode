class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumS = 0, sumT = 0;
        for (char c : s) sumS += c;
        for (char c : t) sumT += c;
        return sumT - sumS;
    }
};