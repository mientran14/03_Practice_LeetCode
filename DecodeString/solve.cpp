class Solution {
public:
    string decodeString(string s) {
        stack<int> countkStack;
        stack<string> stringStack;
        string result = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) k = k*10 + (c - '0');
            else if (c == '[') {
                countkStack.push(k);
                stringStack.push(result);
                k = 0;
                result = "";
            } 
            else if (c == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();
                int repeatCount = countkStack.top();
                countkStack.pop();

                while (repeatCount--) {
                    decodedString += result;
                }
                result = decodedString;
            } 
            else result += c;
        }

        return result;
    }
};