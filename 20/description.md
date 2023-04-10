# 20. Valid Parentheses
###### tags: `leetcode`
## Description
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

- Example 1:

>Input: s = "()"
Output: true

- Example 2:

>Input: s = "()[]{}"
Output: true

- Example 3:

>Input: s = "(]"
Output: false

- Constraints:

>$1 \leq s.length \leq 10^4$
s consists of parentheses only `'()[]{}'`.

## Solution
- The problem can be solved by using the stack STL.
- Check the length first
```cpp=
if (s.length() % 2) return false;
```
- For all the characters in string, put in the stack if it is the front parathese.
```cpp=
if (i == '(' || i == '[' || i == '{') sta.push(int(i));
```
- Check the corresponding FIFO parathese if it is the pair of it
```cpp=
else
{
    if (sta.empty()) return false;
    temp = int(i) - sta.top();
    sta.pop();
    if (temp < 0 || temp > 2) return false;
}
```
- When finishing, check the leftover of the stack
```cpp=
return sta.empty();
```
