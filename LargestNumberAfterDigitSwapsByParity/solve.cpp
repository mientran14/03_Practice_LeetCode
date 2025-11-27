class Solution {
public:
    int largestInteger(int num) {
        vector<int> digits;
        int result = 0;

        int tmp = num;
        while (tmp) {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        priority_queue<int> odds, evens;
        for (int d : digits) {
            if (d % 2 == 1) {
                odds.push(d);
            } else {
                evens.push(d);
            }
        }
        
        for (int d : digits) {
            if (d % 2 == 1) { 
                result = result * 10 + odds.top();
                odds.pop();
            } else {     
                result = result * 10 + evens.top();
                evens.pop();
            }
        }
        return result;
    }
};
