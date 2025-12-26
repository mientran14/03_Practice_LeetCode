class Solution {
public:
    int bestClosingTime(string customers) {
        // // LTE.......................
        // int minPen = INT_MAX;
        // int result = 0;
        // for (int j = 0; j <= customers.size(); j++) {
        //     int curPen = 0;
        //     for (int i = 0; i < customers.size(); i++) {
        //         if (i < j && customers[i] == 'N') {
        //             curPen++;
        //         } else if (i >= j && customers[i] == 'Y') {
        //             curPen++;
        //         }
        //     }
        //     if (curPen < minPen) {
        //         minPen = curPen;
        //         result = j;
        //     }
        // }
        // return result;


        int result = 0;
        int curN = 0, curY = 0;
        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }
        // Prefix sum
        int minPen = totalY;
        for (int j = 0; j <= customers.size(); j++) {
            int curPen = curN + (totalY - curY);
            if (curPen < minPen) {
                minPen = curPen;
                result = j;
            }
            if (j < customers.size()) {
                if (customers[j] == 'N') curN++;
                if (customers[j] == 'Y') curY++;
            }
        }
        return result;
    }
};
