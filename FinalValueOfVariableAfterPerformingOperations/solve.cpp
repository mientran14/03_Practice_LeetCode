class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (string o : operations) {
            if(o == "++X" || o == "X++") X++;
            else X--;
        }
        return X;
    }
};