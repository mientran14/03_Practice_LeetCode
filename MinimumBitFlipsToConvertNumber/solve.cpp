class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count1XOR = start ^ goal;
        int result = 0;

        // while (count1XOR > 0) {
        //     result += count1XOR & 1;
        //     count1XOR >>= 1;
        // }

        while (count1XOR > 0) {
            count1XOR &= (count1XOR - 1);
            result++;
        }
        
        return result;
    }
};