class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;

        for (int i = n-1; i > 0; i--) {
            if (colors[0] != colors[i]) {
                result = max(result, i);
                break;
            }
        }
        
        for (int j = 0; j < n-1; j++) {
            if (colors[n-1] != colors[j]) {
                result = max(result, (n-1)-j);
                break;
            }
        }

        return result;
    }
};
