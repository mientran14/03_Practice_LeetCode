class Solution {
public:
    bool isPalindrome(string s) {
        // int left = 0, right = s.size() - 1;
        // while (left < right) {
        //     if (!isalnum(s[left])) {
        //         left++;
        //         continue;
        //     }  
        //     if (!isalnum(s[right])) {
        //         right--;
        //         continue;
        //     }  
        //     if (tolower(s[left]) != tolower(s[right])) return false;
        //     left++;
        //     right--;
        // }
        // return true;

        string nStr = "";
        for (char c : s) {
            if (isalnum(c)) {
                nStr += tolower(c);
            }
        }
        string reversed = nStr;
        reverse(reversed.begin(), reversed.end());
        
        return nStr == reversed;
    }
};