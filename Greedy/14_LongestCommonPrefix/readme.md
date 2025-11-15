https://leetcode.com/problems/longest-common-prefix/description/

```python
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
```
-----------------------------------------------------------------------------------------
## SOLUTION: 
Duyệt qua từng kí tự tại cùng 1 vị trí trong tất cả các chuỗi.
Nếu kí tự tại vị trí đó không khớp ở bất kỳ chuỗi nào thì dừng lại và trả về common prefix.
