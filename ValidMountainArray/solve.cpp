class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;

        // int left = 0, right = arr.size() - 1;
        // while (left+1 < arr.size() && arr[left] < arr[left+1]) left++;
        // while (right > 0 && arr[right] < arr[right-1]) right--;
        // return left > 0 && right < arr.size()-1 && left == right;

        int i = 0;
        while (i+1 < arr.size() && arr[i] < arr[i+1]) i++;
        if (i==0 || i==arr.size()-1)  return false;
        while (i+1 < arr.size() && arr[i] > arr[i+1]) i++;
        return i == arr.size()-1;
    }
};
