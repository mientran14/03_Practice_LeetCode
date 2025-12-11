class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, pair<int, int>> hashRow, hashCol;
    int result = 0;

    for (auto b : buildings) {
        int x = b[0], y = b[1];

        if (hashRow.find(y) == hashRow.end()) {
            hashRow[y] = {x, x};
        } else {
            hashRow[y].first = min(hashRow[y].first, x);
            hashRow[y].second = max(hashRow[y].second, x);
        }

        if (hashCol.find(x) == hashCol.end()) {
            hashCol[x] = {y, y};
        } else {
            hashCol[x].first = min(hashCol[x].first, y);
            hashCol[x].second = max(hashCol[x].second, y);
        }
    }

    for (auto b : buildings) {
        int x = b[0], y = b[1];

        bool coveredRow = (x > hashRow[y].first && x < hashRow[y].second);
        bool coveredCol = (y > hashCol[x].first && y < hashCol[x].second);
        
        if (coveredRow && coveredCol) {
            result++;
        }
    }
    return result;
    }
};