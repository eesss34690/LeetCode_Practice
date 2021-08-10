# 415_Add_Strings
###### tags: `leetcode` `415`
## Problem Statement
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

- Example 1:

> Input: num1 = "11", num2 = "123"
Output: "134"
- Example 2:

> Input: num1 = "456", num2 = "77"
Output: "533"
- Example 3:

> Input: num1 = "0", num2 = "0"
Output: "0"
 
- Constraints:

> $1 \leq num1.length,\ num2.length \leq 10^4$
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
## Solution
- Just do it with string is better for the large number and it is simple.
- Make sure the ```num2``` is the one with more and the same number of digits and the ```ans``` follows it.
```cpp=
string ans= num2; // big one
int small, plus= 0;
if (num1.size()> num2.size())
{
    ans= num1;
    num1= num2;
    num2= ans;
}
```
- Then start the calculation by backward order. See whether the digits have shift until the smaller ```num1``` runs out of digits.
```cpp=
int i= ans.size()- 1, j= num1.size()- 1;
for (; j> -1; i--, j--)
{
    plus+= (num1[j]- '0')+ (num2[i]- '0');
    if (plus> 9)
    {
        ans[i]= (plus- 10)+ '0';
        plus= 1;
    }
    else
    {
        ans[i]= plus+ '0';
        plus= 0;
    }
}
```
- After that, the part remains for the larger numver of digits ```num2``` and see whether there are still shift left until there is no shift.
```cpp=
while (plus&& i> -1)
{
    plus+= (num2[i]- '0');
    if (plus> 9)
    {
        ans[i--]= (plus- 10)+ '0';
        plus= 1;
    }
    else
    {
        ans[i]= plus+ '0';
        return ans;
    }
}
```
- One more exception (eg. $1+99=100$), If there is one more new digit generated, add it.

```cpp=
if (plus&& i== -1)
    ans.insert(0, "1");
```