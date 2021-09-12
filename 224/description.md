# 224 Basic Calculator
###### tags: `leetcode` `224`
## Problem Statement
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

:::info
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
:::
- Example 1:

> Input: s = "1 + 1"
Output: 2
- Example 2:

> Input: s = " 2-1 + 2 "
Output: 3
- Example 3:

> Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 
- Constraints:

> $1 \leq s.length \leq 3 * 10^5$
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation.
'-' could be used as a unary operation but it has to be inside parentheses.
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer
## Solution
- Do it in default setting for sequential processing. Also do special treatment for ```()```.
- For the normal number, calculate the real number by multiplication and addition.
```cpp=
if(isdigit(s[i])) {
    int val = 0;
                
    while(i < s.length() && isdigit(s[i])) {
        val = val * 10 + (s[i] - '0');
        i++;
    }
                
    result+= (val * sign);
    i--;
}
```
- With operator, remember the sign of it.
```cpp=
else if(s[i] == '+') sign = 1;
else if(s[i] == '-') sign = -1;
```
- If it is the ```(```, use stack to store the current result and the current sign. Since there may be multiple signs, the FILO property can satisfy the condition.
```cpp=
else if(s[i] == '(') {
                
    values.push(result);
    values.push(sign);
                
    result = 0;
    sign = 1;
}
```
- When facing ```)```, the last in is sign, so we have to multiply the sign with the current value inside ```()```. After that, add the stored value.
```cpp=
else {
                
    result *= values.top();
    values.pop();
    result += values.top();
    values.pop();
}
```