## Problem

https://leetcode.com/problems/roman-to-integer/description/

```
```

## Observations

## Solution
Duyệt qua chuỗi Roman từ trái qua phải:
+ Nếu giá trị của kí tự hiện tại [s[i]] < [s[i+1]] thì trừ giá trị của [s[i]] vào tổng.
+ Nếu giá trị của kí tự hiện tại [s[i]] > [s[i+1]] thì cộng giá trị của [s[i]] vào tổng.

# Tags
Hashtable

