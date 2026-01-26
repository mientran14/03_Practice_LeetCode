class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        vector<vector<int>> result;

        for (int i = 1; i < arr.size(); i++) {
            min_diff = min(min_diff, arr[i] - arr[i - 1]);
        }

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == min_diff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
};
