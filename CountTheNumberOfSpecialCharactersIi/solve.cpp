class Solution {
public:
    int numberOfSpecialChars(string word) {
        int result = 0;
        vector<int> lastLo(26, -1);
        vector<int> firstUp(26, -1);

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                lastLo[c - 'a'] = i;
            } 
            else if (isupper(c)) {
                if (firstUp[c - 'A'] == -1) {
                    firstUp[c - 'A'] = i;
                }
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (lastLo[i] != -1 && firstUp[i] != -1 && lastLo[i] < firstUp[i]) {
                result++;
            }
        }

        return result;
    }
};