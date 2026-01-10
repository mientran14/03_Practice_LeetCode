class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> memo(n1, vector<int>(n2, -1));

        // function<int(int, int)> F = [&](int i1, int i2) -> int {
        //     if (i1 < 0) {
        //         int sum = 0;
        //         for (int s = 0; s <= i2; s++) sum += s2[s];
        //         return sum;
        //     }
        //     if (i2 < 0) {
        //         int sum = 0;
        //         for (int s = 0; s <= i1; s++) sum += s1[s];
        //         return sum;
        //     }

        //     if (memo[i1][i2] != -1) return memo[i1][i2];

        //     if (s1[i1] == s2[i2]) {
        //         memo[i1][i2] = F(i1 - 1, i2 - 1);
        //     } 
        //     else {
        //         memo[i1][i2] = min(
        //             F(i1 - 1, i2) + s1[i1],
        //             F(i1, i2 - 1) + s2[i2]
        //         );
        //     }

        //     return memo[i1][i2];
        // };
        // return F(n1 - 1, n2 - 1);

        
        int total_sum = accumulate(s1.begin(), s1.end(), 0) + accumulate(s2.begin(), s2.end(), 0);

        function<int(int, int)> F = [&](int i1, int i2) -> int {
            if (i1 < 0 || i2 < 0) return 0;

            if (memo[i1][i2] != -1) return memo[i1][i2];

            if (s1[i1] == s2[i2]) {
                memo[i1][i2] = s1[i1] + s2[i2] + F(i1 - 1, i2 - 1);
            } 
            else {
                memo[i1][i2] = max(F(i1 - 1, i2), F(i1, i2 - 1));
            }

            return memo[i1][i2];
        };

        return total_sum - F(n1 - 1, n2 - 1);
    }
};
