class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;

        for (string& op : operations) {
            if (op == "+") {
                int n = scores.size();
                scores.push_back(scores[n-1] + scores[n-2]);
            } else if (op == "D") {
                scores.push_back(2 * scores.back());
            } else if (op == "C") {
                scores.pop_back();
            } else {
                scores.push_back(std::stoi(op));
            }
        }

        return accumulate(scores.begin(), scores.end(), 0);
    }
};