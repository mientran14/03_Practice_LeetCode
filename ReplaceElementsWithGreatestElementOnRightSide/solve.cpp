class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
    //     for (int i=0; i < arr.size()-1; i++) {
    //         arr[i] = *max_element(arr.begin()+i + 1, arr.end());
    //     }
    //     arr[arr.size()-1] = -1;
    //     return arr;
    // }

        int maxRight = -1;
        for (int i=arr.size()-1; i >= 0; i--) {
            int curr = arr[i];
            arr[i] = maxRight;
            maxRight = max(maxRight, curr);
        }
        return arr;
    }
};