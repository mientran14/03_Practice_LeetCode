class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        for (const string& w : words) {
            int weight = 0;
            for (char c : w) weight += weights[c - 'a'];
            int mod = weight % 26;
            char resWrd = 'z' - mod;
            result += resWrd;
        }
        return result;
    }
};