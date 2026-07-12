class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> tmpArr = arr;
        sort(tmpArr.begin(), tmpArr.end());
        unordered_map <int, int> rankMap;
        int rank = 1;

        for (int a : tmpArr) {
            if (rankMap.find(a) == rankMap.end()) rankMap[a] = rank++;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rankMap[arr[i]];
        }
        
        return arr;
    }
};