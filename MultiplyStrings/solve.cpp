class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> product(num1.size() + num2.size(), 0);
        string result = "";

        for (int i = num1.size()-1; i >= 0; i--) {
            for (int j = num2.size()-1; j >= 0; j--) {
                int mult = (num1[i] - '0') *(num2[j] - '0');
                int sumdigit = mult + product[i+j+1];

                product[i+j+1] = sumdigit % 10;
                product[i+j] += sumdigit/10;
            }
        }

        for (int p : product) {
            if (!(result.empty() && p == 0)) {
                result += to_string(p);
            }
        }

        return result.empty() ? "0" : result;
    }
};
