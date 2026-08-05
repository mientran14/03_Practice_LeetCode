class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    //----------------------------------------TLE 774/775 testcases--------------------------------------
        vector<bool> isSuspicious(n, false);
        isSuspicious[k] = true;
        // Nếu a suspicious thì b cũng suspicious
        bool flag = true;
        while (flag) {
            flag = false;
            for (auto& inv : invocations) {
                int a = inv[0];
                int b = inv[1];
                if (isSuspicious[a] && !isSuspicious[b]) {
                    isSuspicious[b] = true;
                    flag = true;
                }
            }
        }
        for (auto& inv : invocations) {
            int a = inv[0];
            int b = inv[1];
            // If it is not possible to remove all the suspicious methods, none should be removed.
            if (!isSuspicious[a] && isSuspicious[b]) {
                vector<int> all(n);
                for (int i = 0; i < n; ++i) all[i] = i;
                return all;
            }
        }
        vector<int> remain;
        for (int i = 0; i < n; ++i) {
            if (!isSuspicious[i]) {
                remain.push_back(i);
            }
        }
        return remain;
        

    //----------------------------------------Accepcted-------------------------------------------------
        vector<vector<int>> graph(n);
        for (auto& inv : invocations) {
            graph[inv[0]].push_back(inv[1]);
        }

        vector<bool> isSuspicious(n, false);

        function<void(int)> dfs = [&](int a) {
            isSuspicious[a] = true;
            for (int b : graph[a]) {
                if (!isSuspicious[b]) {
                    dfs(b);
                }
            }
        };

        dfs(k);
        
        for (auto& inv : invocations) {
            int a = inv[0];
            int b = inv[1];
            // If it is not possible to remove all the suspicious methods, none should be removed
            if (!isSuspicious[a] && isSuspicious[b]) {
                vector<int> all(n);
                for (int i = 0; i < n; ++i) all[i] = i;
                return all;
            }
        }

        vector<int> remain;
        for (int i = 0; i < n; i++) {
            if (!isSuspicious[i]) {
                remain.push_back(i);
            }
        }

        return remain;
    }
};