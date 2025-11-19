class Solution {
public:
    int countVowelSubstrings(string word) {

    auto charvowels = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    
    int result = 0;

    for (int i=0; i<word.size(); i++) {
        unordered_map<char, int> countvowels;
        bool flag = true;

        for (int j=i; j<word.size(); j++) {
            char c = word[j];

            if (!charvowels(c)) {
                flag = false;
                break;
            }
            countvowels[c]++;

            if (countvowels.size() == 5) {
                result++;
            }
        }
    }
    return result;
}
};
