class Solution {
public:
    bool isThree(int n) {
        // int count = 0;
        // for (int i=1; i<=n; i++) {
        //     if (n%i == 0) {
        //         count++;
        //     }
        // }
        // return (count==3);

        // Optional: list divisors
        // vector<int> divisors;
        // for (int i = 1; i*i <= n; i++) {
        //     if (n%i == 0) {
        //         divisors.push_back(i);
        //         if (i*i != n) {
        //             divisors.push_back(n/i);
        //         }
        //     }
        // }
        // sorft (divisors.begin(), divisors.end());
        // return divisors;

        int count = 0;
        for (int i = 1; i*i <= n; i++) {
            if (n%i == 0) {
                count++;
                if (i*i != n) {
                    count++;
                }
            }
        }
        return count == 3;
    }
};
