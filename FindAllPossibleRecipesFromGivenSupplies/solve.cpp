class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph; // Lên công thức
        unordered_map<string, int> needed;
        unordered_set<string> menu(recipes.begin(), recipes.end());
        vector<string> result;
        
        // Mỗi món thiếu bao nhiêu ingredients?
        // ingredients này sẽ dùng cho những món nào tiếp theo?
        for (size_t i = 0; i < recipes.size(); ++i) {
            needed[recipes[i]] = ingredients[i].size();
            for (string& igrd : ingredients[i]) {
                graph[igrd].push_back(recipes[i]);
            }
        }
        
        // Cất đồ vào tủ lạnh
        queue<string> supply;
        for (string& s : supplies) supply.push(s);

        while (!supply.empty()) {
            // Lấy ng.lieu
            string item = supply.front();
            supply.pop();
            
            // Nếu đồ lấy ra là món trong menu -> okeee lên mâm
            if (menu.count(item)) result.push_back(item);
            
            // Trong công thức, đồ này còn nấu đc cho món nào
            for (string& i : graph[item]) {
                // Gạch bớt một ng.liệu cần trong công thức
                needed[i] = needed[i] - 1; 

                // Xem món đó đã đủ hết đồ để nấu chưa
                if (needed[i] == 0) {
                    // Đủ đồ để nấu -> cất vào tủ lạnh để làm ng.lieu cho món sau
                    supply.push(i);
                }
            }
        }
        
        return result;
    }
};