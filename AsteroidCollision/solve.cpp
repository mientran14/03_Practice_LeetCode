class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stackS;

        for (int a : asteroids) {
            bool isExploded = false;

            while (!stackS.empty() && a < 0 && stackS.top() > 0) {
                if (abs(stackS.top()) < abs(a)) {
                    stackS.pop();
                } 
                else if (abs(stackS.top()) == abs(a)) {
                    stackS.pop();
                    isExploded = true;
                    break;
                } 
                else {
                    isExploded = true;
                    break;
                }
            }

            if (!isExploded) stackS.push(a);
        }

        vector<int> result(stackS.size());
        for (int i = stackS.size() - 1; i >= 0; i--) {
            result[i] = stackS.top();
            stackS.pop();
        }

        return result;
    }
};