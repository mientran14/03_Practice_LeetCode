class Solution {
public:
    string winningPlayer(int x, int y) {
        int count = min(x, y/4);
        return (count % 2 == 1) ? "Alice" : "Bob";
    }
};