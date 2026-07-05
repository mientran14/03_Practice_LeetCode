class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        vector<vector<int>> maxSum(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> paths(n + 1, vector<int>(n + 1, 0));
        maxSum[n-1][n-1] = 0;
        paths[n-1][n-1] = 1;

        for (int r = n - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (board[r][c] == 'X' || (r == n - 1 && c == n - 1)) continue;
                
                int maxNext = max({maxSum[r+1][c], maxSum[r][c+1], maxSum[r+1][c+1]});

                if (maxNext == -1) continue;
                
                int val = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
                maxSum[r][c] = maxNext + val;
                
                if (maxSum[r+1][c] == maxNext) {
                    paths[r][c] = (paths[r][c] + paths[r+1][c]) % MOD;
                }
                if (maxSum[r][c+1] == maxNext) {
                    paths[r][c] = (paths[r][c] + paths[r][c+1]) % MOD;
                }
                if (maxSum[r+1][c+1] == maxNext) {
                    paths[r][c] = (paths[r][c] + paths[r+1][c+1]) % MOD;
                }
            }
        }
        if (maxSum[0][0] == -1) return {0, 0};
        
        return {maxSum[0][0], paths[0][0]};
    }
};