class Solution {
public:
    int numOfWays(int n) {
        // n = 1:
        // RYR, RGR, YGY, GRG, YRY, GYG -> Type2color = 6 ways
        // RYG, RGY, YRG, YGR, GRY, GYR -> Type3color = 6 ways
        // -> sum1 = Type2color + Type2color = 12

        // n = 2:
        // If at the n=1 (means n-1), it's Type2color: 
        //    + case1: Type2color: RYR -> YRY, GRG, YGY -> 3 ways 
        //    + case2: Type3color: RYR -> GRY, YGR -> 2 ways
        // If at the n=1 (means n-1), it's Type3color: 
        //    + case1: Type2color: RYG -> YRY, YGY -> 2 ways 
        //    + case2: Type3color: RYG -> GRY, YGR -> 2 ways


        const int MOD = 1e9 + 7;
        long long Type2color = 6;
        long long Type3color = 6;

        for (int i = 2; i <= n; i++) {
            long long newType2color = (3 * Type2color + 2 * Type3color) % MOD;
            long long newType3color = (2 * Type2color + 2 * Type3color) % MOD;

            Type2color = newType2color;
            Type3color = newType3color;
        }

        return (Type2color + Type3color) % MOD;
    }
};
