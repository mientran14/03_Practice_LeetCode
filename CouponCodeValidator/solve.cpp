class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> result;
        unordered_map<string, int> business {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3},
        };

        auto isvalidCode = [](string & s) -> bool {
            if (s.empty()) return false;
            for (char c : s) {
                if (!(isalnum(c) || c=='_')) return false;
            }
            return true;
        };

        vector<pair<int,string>> couponValid;
        for (int i=0; i<code.size(); i++) {
            if (!isvalidCode(code[i])) continue; 
            if (!isActive[i]) continue; 
            auto it = business.find(businessLine[i]);
            if (it == business.end()) continue;
            couponValid.push_back({it->second, code[i]});
        }

        sort(couponValid.begin(), couponValid.end(), [](auto& a, auto& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        for (auto& c: couponValid) {
            result.push_back(c.second);
        }
        
        return result;
    }
};