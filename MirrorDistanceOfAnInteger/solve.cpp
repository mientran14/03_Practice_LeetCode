class Solution {
public:
    int mirrorDistance(int n) {
        // int reverse = 0, origin = n;
        // while(n > 0) {
        //     int digit = n % 10;
        //     reverse = reverse * 10 + digit;
        //     n /= 10;
        // }
        // return abs(origin - reverse);

        string n2str = to_string(n);
        reverse(n2str.begin(), n2str.end());
        int reverse = stoi(n2str);
        return abs(n-reverse);
    }
};