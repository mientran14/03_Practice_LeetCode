// class Solution {
// public:
//     int numSteps(string s) {
//         int result = 0;
//         while (s != "1") {
//             if (s.back() == '0') s.pop_back();
//             else {
//                 int i = s.size() - 1;
//                 while (i >= 0 && s[i] == '1') s[i--] = '0';
//                 if (i >= 0) s[i] = '1';
//                 else s = "1" + s;
//             }
//             result++;
//         }
//         return result;
//     }
// };



template <std::size_t N>
void increment(std::bitset<N>& bs)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        bs.flip(i);
        if (bs.test(i))
        {
            break;
        }
    }
}

class Solution
{
public:
    int numSteps(const string& s)
    {
        int steps = 0;
        std::bitset<500> bits(s);
        std::bitset<500> check("1");
        while (bits != check)
        {
            if (bits.test(0))
            {
                increment(bits);
            }
            else
            {
                bits >>= 1;
            }
            steps += 1;
        }
        return steps;
    }
};