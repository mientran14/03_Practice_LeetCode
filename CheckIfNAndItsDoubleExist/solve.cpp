class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // for (int i = 0; i < arr.size(); i++) {
        //     for (int j = 0; j < arr.size(); j++) {
        //         if (i != j && arr[i] == 2*arr[j]) {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // Binary search
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            int target = 2 * arr[i];

            int left = 0, right = arr.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target && mid != i) {
                    return true; 
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
