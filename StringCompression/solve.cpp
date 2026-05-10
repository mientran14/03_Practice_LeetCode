class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0, count = 1;
        for (int i = 1; i <= chars.size(); i++) {
            if (i == chars.size() || chars[i] != chars[i-1]) {
                chars[idx++] = chars[i-1];
                if (count > 1) {
                    for (char c : to_string(count)) {
                        chars[idx++] = c;
                    }
                }
                count = 1;
            } 
            else count++;
        }
        return idx;
    }
};