class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        // int n = stoneValue.size();
        // int dp1 = 0; // dp[i+1]
        // int dp2 = 0; // dp[i+2]
        // int dp3 = 0; // dp[i+3]
        // for (int i = n - 1; i >= 0; i--) {
        //     int curSum = 0;
        //     int maxDiff = INT_MIN;
        //     for (int k = 0; k < 3 && i + k < n; k++) {
        //         curSum += stoneValue[i + k];
        //         int nextDp = 0;
        //         if (k == 0) nextDp = dp1;      // dp[i+1]
        //         else if (k == 1) nextDp = dp2; // dp[i+2]
        //         else if (k == 2) nextDp = dp3; // dp[i+3]
        //         maxDiff = max(maxDiff, curSum - nextDp);
        //     }
        //     dp3 = dp2;
        //     dp2 = dp1;
        //     dp1 = maxDiff;
        // }
        // int aliceDiff = dp1;
        // if (aliceDiff > 0) return "Alice";
        // if (aliceDiff < 0) return "Bob";
        // return "Tie";

        int n = stoneValue.size();
        vector<int> dp(n+1, 0);
        int suffixSum = 0;
        
        for (int i = n-1; i >= 0; i--) {
            suffixSum += stoneValue[i];
            
            int minNext = dp[i + 1];                                // take 1 stone
            if (i + 2 <= n) minNext = min(minNext, dp[i + 2]);      // take 2 stones
            if (i + 3 <= n) minNext = min(minNext, dp[i + 3]);      // take 3 stones
            
            dp[i] = suffixSum - minNext;
        }
        
        int aliceScore = dp[0];
        int totalScore = suffixSum;
        int bobScore = totalScore - aliceScore;
        
        if (aliceScore > bobScore) return "Alice";
        if (aliceScore < bobScore) return "Bob";
        return "Tie";
    }
};