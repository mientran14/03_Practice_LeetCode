class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for (const string& q : queries) {
            for (const string& d : dictionary) {
                vector<int> diffInd;
                for (int i = 0; i < q.size(); i++) {
                    if (q[i] != d[i]) {
                        diffInd.push_back(i);
                        if (diffInd.size() > 2) break;
                    }
                }
                if (diffInd.size() <= 2) {
                    result.push_back(q);
                    break;
                }
            }
        }
        return result;
    }
};