class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        sort(arr2.begin(), arr2.end());
        for (int x : arr1) {
            int lower = x - d;
            int upper = x + d;
            auto it1 = lower_bound(arr2.begin(), arr2.end(), lower);
            auto it2 = upper_bound(arr2.begin(), arr2.end(), upper);
            if (it1 == it2) {
                count++;
            }
        }

        // for (int i = 0; i < arr1.size(); i++) {
        //     bool isValid = true;
        //     for (int j = 0; j < arr2.size(); j++) {
        //         if (abs(arr1[i] - arr2[j]) <= d) {
        //             isValid = false;
        //             break;
        //         }
        //     }
        //     if (isValid) {
        //         count++;
        //     }
        // }

        // sort(arr2.begin(), arr2.end());
        // for (int i = 0; i < arr1.size(); i++) {
        //     int l = 0, r = arr2.size()-1;
        //     bool isValid = true;
        //     while (l<=r) {
        //         int m = l + (r-l)/2;
        //         if (abs((arr1[i] - arr2[m])) <= d) {
        //             isValid = false;
        //             break;
        //         }
        //         if (arr2[m] < arr1[i]) {
        //             l = m + 1 ;
        //         }
        //         else {
        //             r = m - 1;
        //         }
        //     }
        //     if (isValid) {
        //         count++;
        //     }
        // }

        return count;
    }
};
