# 66_Plus_One
###### tags: `leetcode` `66`
## Problem Statement
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.


- Example 1:

> Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
- Example 2:

> Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
- Example 3:

> Input: digits = [0]
Output: [1]

- Constraints:

> 1 <= digits.length <= 100
0 <= digits[i] <= 9
## Solution
- The problem there is carry. To tackle this, use a while loop to turn the last element into 0 till there is no 9.
```cpp=
while (i> -1&& digits[i]== 9)
{
    digits[i--]= 0;
}
```
- the last one need to tell whether there is other element that is not 9. If none, add a 1 into the vector, else turn that element add 1.
```cpp=
if (i== -1)
    digits.insert(digits.begin(), 1);
else
    digits[i]++;
```