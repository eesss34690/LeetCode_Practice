# 59. Spiral Matrix II
###### tags: `leetcode`
## Description
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

- Example 1:
![](https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg)

>Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

- Example 2:

>Input: n = 1
Output: [[1]]

- Constraints:

>1 <= n <= 20

## Solution
- The solution is to simulate the flow for the iteration.
- Use bounadry check for the value
- Because we only have square, the check for the value can be done by only one value
```cpp=
while (top <= buttom)
```
- Start with the top first, amnd then iterate down, buttom, and up again
```cpp=
for (i = left; i <= right; i++) ans[top][i] = cnt++;
top++;
if (top <= buttom)
{
    for (i = top; i <= buttom; i++) ans[i][right] = cnt++;
    right--;
    for (i = right; i >= left; i--) ans[buttom][i] = cnt++;
    buttom--;
    for (i = buttom; i >= top; i--) ans[i][left] = cnt++;
    left++;
}
```