class NeighborSum {
public:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> hashNeighbor;

    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid.size(); col++) {
                int value = grid[row][col];
                hashNeighbor[value] = {row, col};
            }
        }
    }
    
    int adjacentSum(int value) {
        if (hashNeighbor.find(value) == hashNeighbor.end()) return 0;

        int row = hashNeighbor[value].first;
        int col = hashNeighbor[value].second;
        int sum = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid.size()) {
                sum += grid[newRow][newCol];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        if (hashNeighbor.find(value) == hashNeighbor.end()) return 0;

        int row = hashNeighbor[value].first;
        int col = hashNeighbor[value].second;
        int sum = 0;

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid.size()) {
                sum += grid[newRow][newCol];
            }
        }
        return sum;
    }
};
