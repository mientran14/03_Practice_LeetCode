class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        // // Greedy1: Failed
        // // Cách làm này chỉ xử lý trường hợp loại bỏ một phần tử nhỏ nhất để tổng chia hết cho 3.
        // // Mà không kiểm tra xem có thể giữ lại các phần tử khác để đạt tổng lớn hơn.
        // // Ví du: nums = [2,6,2,2,7], Output=12, Expected=15
        // // Thay vì trừ đi (2+2) lại trừ đi 7
        // int totalSum = 0;
        // int minR1 = INT_MAX, minR2 = INT_MAX;

        // for (int num : nums) {
        //     totalSum += num;
        //     if (num % 3 == 1) {
        //         minR1 = min(minR1, num);
        //     } else if (num % 3 == 2) {
        //         minR2 = min(minR2, num);
        //     }
        // }

        // if (totalSum % 3 == 0) return totalSum;

        // if (totalSum % 3 == 1) {
        //     return totalSum - minR1;
        // } else { 
        //     return totalSum - minR2;
        // }

        //////////////////////////////////////////////////////////////////////////////////////////////
        // // Greedy2: Pass
        // int totalSum = 0;
        // int min1R1 = INT_MAX, min2R1 = INT_MAX;
        // int min1R2 = INT_MAX, min2R2 = INT_MAX;

        // for (int num : nums) {
        //     totalSum += num;
        //     if (num % 3 == 1) {
        //         if (num < min1R1) {
        //             min2R1 = min1R1;
        //             min1R1 = num;
        //         } else if (num < min2R1) {
        //             min2R1 = num;
        //         }
        //     } else if (num % 3 == 2) {
        //         if (num < min1R2) {
        //             min2R2 = min1R2;
        //             min1R2 = num;
        //         } else if (num < min2R2) {
        //             min2R2 = num;
        //         }
        //     }
        // }

        // if (totalSum % 3 == 0) return totalSum;

        // if (totalSum % 3 == 1) {
        //     int opt1 = (min1R1 != INT_MAX) ? totalSum - min1R1 : 0;
        //     int opt2 = (min1R2 != INT_MAX && min2R2 != INT_MAX) ? totalSum - min1R2 - min2R2 : 0;
        //     return max(opt1, opt2);
        // } else if (totalSum % 3 == 2) { 
        //     int opt1 = (min1R2 != INT_MAX) ? totalSum - min1R2 : 0;
        //     int opt2 = (min1R1 != INT_MAX && min2R1 != INT_MAX) ? totalSum - min1R1 - min2R1 : 0;
        //     return max(opt1, opt2);
        // }
        // return 0;

        //////////////////////////////////////////////////////////////////////////////////////////////
        // Dynamic Programming: Pass
        vector<int> dpSumDiv = {0, INT_MIN, INT_MIN};

        for (int num : nums) {
            vector<int> current(dpSumDiv);
            for (int r = 0; r < 3; r++) {
                if (current[r] != INT_MIN) {
                    int newR = (current[r] + num) % 3;
                    dpSumDiv[newR] = max(dpSumDiv[newR], current[r] + num);
                }
            }
        }
        return dpSumDiv[0];
    }
};