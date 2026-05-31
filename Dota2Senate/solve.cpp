class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> queueR, queueD;

        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') queueR.push(i);
            else queueD.push(i);
        }

        while (!queueR.empty() && !queueD.empty()) {
            int idxR = queueR.front();
            queueR.pop();
            int idxD = queueD.front();
            queueD.pop();

            if (idxR < idxD) {
                queueR.push(idxR + senate.size());
            } 
            else queueD.push(idxD + senate.size());
        }

        return queueR.empty() ? "Dire" : "Radiant";
    }
};