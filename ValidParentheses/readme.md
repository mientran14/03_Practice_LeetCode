## Problem

https://leetcode.com/problems/valid-parentheses/description/

```
```

## Observations

## Solution
Lưu các dấu ngoặc mở bằng stack.
Duyệt qua từng kí tự trong chuỗi:
+ Nếu là dấu ngoặc đóng, kiểm tra tính hợp lệ (xem nó có khớp với dấu ngoặc mở gần nhất topstack không):
    - Nếu khớp, loại bỏ dấu ngoặc mở khỏi stack.
    - Nếu không khớp, return false.
+ Nếu là dấu ngoặc mở, đẩy vào stack.
Kết thúc duyệt chuỗi:
+ Nếu stack rỗng -> Output: true
+ Nếu stack không rỗng -> Output: false

# Tags
Stack

