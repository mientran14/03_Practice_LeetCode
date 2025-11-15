https://leetcode.com/problems/valid-parentheses/description/

```python
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Example 5:
Input: s = "([)]"
Output: false

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
```
-----------------------------------------------------------------------------------------
## SOLUTION: 
Lưu các dấu ngoặc mở bằng stack.
Duyệt qua từng kí tự trong chuỗi:
+ Nếu là dấu ngoặc đóng, kiểm tra tính hợp lệ (xem nó có khớp với dấu ngoặc mở gần nhất topstack không):
    - Nếu khớp, loại bỏ dấu ngoặc mở khỏi stack.
    - Nếu không khớp, return false.
+ Nếu là dấu ngoặc mở, đẩy vào stack.
Kết thúc duyệt chuỗi:
+ Nếu stack rỗng -> Output: true
+ Nếu stack không rỗng -> Output: false
