class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int maxComSize = min(str1.size(), str2.size());
        for (int s = maxComSize; s > 0; s--) {
            string sub = str1.substr(0, s);
            if (str1.size() % s == 0 && str2.size() % s == 0) {
                string repeat1 = "", repeat2 = "";
                for (int i = 0; i < str1.size() / s; i++) repeat1 += sub;
                for (int i = 0; i < str2.size() / s; i++) repeat2 += sub;
                if (repeat1 == str1 && repeat2 == str2) return sub;
                }
            }
        return "";
    }
};