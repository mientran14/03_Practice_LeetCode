class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7;
        long result = 0; 

        unordered_map<long, long> coorYmap;
        for (int i = 0; i < points.size(); i++) {
            coorYmap[points[i][1]]++;
        }

        long sumHori = 0;
        for (auto& i : coorYmap) {
            long count = i.second;
            long pairs = (count * (count - 1)) / 2;
            // result += pairs * sumHori;
            result = (result%MOD + pairs%MOD * sumHori%MOD)%MOD;
            sumHori += pairs;
        }
        
        return result;
    }
};