class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNum;
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {
                    if (i==j || j==k || i==k) continue;
                    int a = digits[i], b = digits[j], c = digits[k];
                    if (a != 0 && c % 2 == 0) {
                        int num = a*100 + b*10 + c;
                        uniqueNum.insert(num);
                    }
                }
            }
        }
        vector<int> result(uniqueNum.begin(), uniqueNum.end());
        sort(result.begin(), result.end());
        return result;
    }
};