class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result(score.size());

        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < score.size(); i++) {
            maxHeap.push({score[i], i});
        }

        int rank = 1;
        while (!maxHeap.empty()) {
            auto [s, i] = maxHeap.top();
            maxHeap.pop();

            if (rank == 1) result[i] = "Gold Medal";
            else if (rank == 2) result[i] = "Silver Medal";
            else if (rank == 3) result[i] = "Bronze Medal";
            else result[i] = to_string(rank);

            rank++;
        }

        return result;
    }
};