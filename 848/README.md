# 848 Shifting Letters
###### tags: `leetcode` `848`
## Problem Statement
You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.
- Example 1:

> Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.
- Example 2:

> Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"
- Constraints:
> $1 \leq s.length \leq 10^5$
s consists of lowercase English letters.
$shifts.length = s.length\\
0 \leq shifts[i] \leq 109$
## Solution
- If you want to use to in accordance to forward sequence, it is bound to be ```TimeLimitExceed```.
- If you use backward sequence, it is much more simple since each one can be achieved by adding the former one and cumulate the sum for the next one.
```cpp=
for(int i=s.size()-1;i>=0;i--){
    s[i]=((s[i]-'a')+(shift+shifts[i]) % 26) % 26 +'a';
    shift+=shifts[i];
}
```