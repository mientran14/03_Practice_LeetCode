class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int distNext = (i - startIndex + n) % n;
                int distprev = (startIndex - i + n) % n;
                result = min(result, min(distNext, distprev));
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};