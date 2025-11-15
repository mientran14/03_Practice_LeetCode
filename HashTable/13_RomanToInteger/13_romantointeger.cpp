class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashroman = {
            {'I', 1}, 
            {'V', 5}, 
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100}, 
            {'D', 500}, 
            {'M', 1000}
        };

        int result = 0;

        for (int i=0; i<s.length(); i++) {
            if (hashroman[s[i]] < hashroman[s[i+1]]) {
                result -= hashroman[s[i]];
            }
            else {
                result += hashroman[s[i]];
            }
        }
        return result;
    }
};