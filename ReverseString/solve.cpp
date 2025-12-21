class Solution {
public:
    void recursive(vector<char>& s, int l, int r){
        if(l >= r) return;
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        recursive(s, ++l, --r);
    }

    void reverseString(vector<char>& s) {
        // reverse(s.begin(), s.end());

        // // Two pointer:
        // int left = 0, right = s.size() - 1;
        // while (left < right) {
        //     swap(s[left], s[right]);
        //     left++;
        //     right--;
        // }

        // Recursive:
        int l = 0;
        int r = s.size() - 1;
        recursive(s, l, r);
    }
};
