class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int count = 0;
        int curleft = -1;
        int curright = -1;

        for (auto& i : intervals) {
            int l = i[0];
            int r = i[1];

            if (l >= curleft && r <= curright) continue;
            if (l == curleft && r >= curright) curright = r;
            else {
                curleft = l;
                curright = r;
                count++;
            }
        }

        return count;
    }
};