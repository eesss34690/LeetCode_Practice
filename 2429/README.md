# 2429. Minimize XOR
###### tags: `leetcode`
## Description
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

- Example 1:

>Input: num1 = 3, num2 = 5
Output: 3
>>Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

- Example 2:

>Input: num1 = 1, num2 = 12
Output: 3
>>Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.

- Constraints:

>1 <= num1, num2 <= 109

## Solution
- When counting the set bit, the result should be 1 plus the original number xor the number minus 1. Because when doing substraction, the least significant 1 will be erased, or the last one will be 0 and all the others becomes 1.
```cpp=
int countSetBit(int num)
{
    if (num == 0)
        return 0;
    else
        return 1 + countSetBit(num & (num - 1));
}
```
- After counting, if the number is the same, the solution should be the original num1, which let the num1 xor answer equal to 0
- If cnt1 is more than cnt2, find the least significant 1 to stay and kill the rest. Use the loop to find the one should be stayed
```cpp=
for (int i = cnt1 - cnt2; i > 0; times = times << 1)
{
    if (temp % 2 == 1)
    {
        i--;
        num1 -= times;
    }
    temp = temp >> 1;
}
return num1;
```
- If cnt2 is more than cnt1, find the gapping 0 inside the num1 from least significant one to add the value.
```cpp=
int dist = cnt2 - cnt1, temp = num1, ans = 0;
while (dist != 0 && temp != 0)
{
    ans = ans << 1;
    ans++;
    if (temp % 2 == 0)
        dist--;
    temp = temp >> 1;
}
```
- If the gapping 0 can make up all the redundant 1, return it with the answer
```cpp=
if (dist == 0)
    return ans | num1;
```
- Else put all the redundant 1 in the most significant bit
```cpp=
for (int i = log(ans) / log(2) + 1; dist > 0; dist--, i++)
    ans += pow(2, i);
return ans;
```
