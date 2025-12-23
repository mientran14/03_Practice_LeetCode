class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // // LTE......................
        // int result = 0;
        // for (int i = 0; i < events.size(); i++) {
        //     for (int j = 0; j < events.size(); j++) {
        //         if (i == j || events[i][1] < events[j][0] || events[j][1] < events[i][0]) {
        //             int currVal = events[i][2];
        //             if (i != j) {
        //                 currVal += events[j][2];
        //             }
        //             result = max(result, currVal);
        //         }
        //     }
        // }
        // return result;

        // Binary Search:
        int result = 0;
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> maxVal(events.size(), 0); 
        maxVal[0] = events[0][2];
        for (int i = 1; i < events.size(); i++) {
            maxVal[i] = max(maxVal[i - 1], events[i][2]);
        }
        
        for (int i = 0; i < events.size(); i++) {
            int currVal = events[i][2];
            int left = 0, right = i - 1;
            int overlapE = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][1] < events[i][0]) {
                    overlapE = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (overlapE != -1) {
                currVal += maxVal[overlapE];
            }

            result = max(result, currVal);
        }

        return result;
    }
};