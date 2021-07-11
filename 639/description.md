# 639_Decode_Ways_II
###### tags: `leetcode` `639`
## Problem Statement
A message containing letters from A-Z can be encoded into numbers using the following mapping:
```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
```
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
```
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

In addition to the mapping above, an encoded message may contain the '*' character, which can represent any digit from '1' to '9' ('0' is excluded). For example, the encoded message "1*" may represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19". Decoding "1*" is equivalent to decoding any of the encoded messages it can represent.

Given a string s containing digits and the '*' character, return the number of ways to decode it.

Since the answer may be very large, return it modulo 109 + 7.

- Example 1:

> Input: s = "*"
Output: 9
Explanation: The encoded message can represent any of the encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or "9".
Each of these can be decoded to the strings "A", "B", "C", "D", "E", "F", "G", "H", and "I" respectively.
Hence, there are a total of 9 ways to decode "*".
- Example 2:

> Input: s = "1*"
Output: 18
Explanation: The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
Hence, there are a total of 9 * 2 = 18 ways to decode "1*".
- Example 3:

> Input: s = "2*"
Output: 15
Explanation: The encoded message can represent any of the encoded messages "21", "22", "23", "24", "25", "26", "27", "28", or "29".
"21", "22", "23", "24", "25", and "26" have 2 ways of being decoded, but "27", "28", and "29" only have 1 way.
Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15 ways to decode "2*".
 
- Constraints:

> 1 <= s.length <= 105
s[i] is a digit or '*'.
## Solution
- This is actually a ```recursive- like``` problem and the quickest way to solve it is by ```dynamic programming```
- To begin with , since the characters can be split from **1 to 26**, the number to store is **the last one** and **the one before the last one**, meaning that the result may stem from the 2 possibilities.
    - ****** (nums[i])
    - ***** (nums[i-1] nums[i])
```cpp=!
for (int i = 1; i < s.size(); ++i) {
    long next = prev * numOfTwoChars(s[i - 1], s[i]) + cur * numOfOneChar(s[i]);
    prev = cur;
    cur = next % 1000000007;
}
```
- To seperate these 2 situations, there are 2 things to look at.
- The one number: if the last one is 0, it is impossible to be independant, if *, it can be range from 1 to 9, else only 1 possible solution.

```cpp=
int numOfOneChar(char a) {
    if (a == '0') {
        return 0;
    } else if (a == '*') {
        return 9;
    }
    return 1;
}
```
- The parameter for 2 digits is more complicated. it is a better appoach to categorize with the first digit as a starter.
- If the first one is *:
    - next is 0-6: 2 possibilities
    - next is *: 15 (11-19, 21-26)
    - next is 7-9: 1 (1*)

```cpp=
if (a == '*') {
    if (b == '*') {
        return 15;
    } else if (b <= '6') {
        return 2;
    } else {
        return 1;
    }
}
```
- If the first is 1:
    - next *: 9
- If the first is 2:
    - next *: 9
    - number< 7: 1

```cpp=
else if (a == '1') {
    return b == '*' ? 9 : 1;
} else if (a == '2') {
    if (b == '*') {
        return 6;
    } else if (b <= '6') {
        return 1;
    } else {
        return 0;
    }
}
```