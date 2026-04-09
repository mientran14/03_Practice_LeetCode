class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string repeat = word;
        while (sequence.find(repeat) != string::npos) {
            k++;
            repeat += word;
        }
        return k;
    }
};