class NeighborSum {
private:
    vector<vector<int>> grid; 
    unordered_map<int, pair<int, int>> sums;

public:
    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid.size(); col++) {
                int value = grid[row][col];

                vector<pair<int, int>> adjacent = {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
                int sumadj = 0;
                for (auto [irow, icol] : adjacent) {
                    if (irow >= 0 && irow < grid.size() && icol >= 0 && icol < grid.size()) {
                        sumadj += grid[irow][icol];
                    }
                }

                vector<pair<int, int>> diagonal = {{row - 1, col - 1}, {row - 1, col + 1}, {row + 1, col - 1}, {row + 1, col + 1}};
                int sumdiag = 0;
                for (auto [irow, icol] : diagonal) {
                    if (irow >= 0 && irow < grid.size() && icol >= 0 && icol < grid.size()) {
                        sumdiag += grid[irow][icol];
                    }
                }

                sums[value] = {sumadj, sumdiag};
            }
        }
    }

    int adjacentSum(int value) {
        if (sums.find(value) != sums.end()) {
            return sums[value].first;
        }
        return 0;
    }

    int diagonalSum(int value) {
        if (sums.find(value) != sums.end()) {
            return sums[value].second;
        }
        return 0;
    }
};