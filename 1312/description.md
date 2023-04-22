# 1312. Minimum Insertion Steps to Make a String Palindrome
###### tags: `leetcode`
## Description
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

- Example 1:

>Input: s = "zzazz"
Output: 0
>>Explanation: The string "zzazz" is already palindrome we do not need any insertions.

- Example 2:

>Input: s = "mbadm"
Output: 2
>>Explanation: String can be "mbdadbm" or "mdbabdm".

- Example 3:

>Input: s = "leetcode"
Output: 5
>>Explanation: Inserting 5 characters the string becomes "leetcodocteel".

- Constraints:

>$1 \leq s.length \leq 500$
s consists of lowercase English letters.

## Solution
- The problem is a dynamic problem. With each of the vector node as the number needed to add for the substring
- To calculate the value, the direction to count should be a starting index in a closest end and move it gradually backward to the starting point
```cpp=
for (int i = n - 2; i >= 0; i--) {
```
- In the iteration, move the end index foreward in order to extend the substring length.
- The calculation should start from length equal to `2` because for length = 1, all of them are palindrome
    - The `prev` starts with `0` because the starting previous value is one character and the number to add is 0
- By extending the length, it means the original substring plus one character in the front because the starting point is moving backward
- Thus, if the front is equal to the back, the dp value is the same
```cpp=
if (s[i] == s[j]) dp[j] = prev;
```
- If the two are different, two possibilities can construct the substring
    - Adding the front character with the rest of the substring
    - Add the back character with the rest of the substring
    - Both possibilities need to add `1` in the back or front
```cpp=
else dp[j] = min(dp[j], dp[j - 1]) + 1;
```
- The previous value is stored as the last time for the substring that is one fore character less from the next iteration
```cpp=
int temp = dp[j];
prev = temp;
```
- Fianlly return back the final value
```cpp=
return dp[n - 1];
```