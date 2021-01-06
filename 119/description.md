# 119_Pascal's_Triangle_II
###### tags: `leetcode` `119`
## Problem Statement
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
- Notice that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

- Follow up:

> Could you optimize your algorithm to use only O(k) extra space?

- Example 1:

> Input: rowIndex = 3
> Output: [1,3,3,1]
- Example 2:

> Input: rowIndex = 0
> Output: [1]
- Example 3:

> Input: rowIndex = 1
> Output: [1,1]

- Constraints:

> 0 <= rowIndex <= 33
## Solution
- Because the result only contains 1 lines, use ```recursive addition``` to...
    - add 1 tail element
    - add the values inside the array
```cpp=
vector<int> result(1,1);
for (int i= 0; i< rowIndex; i++)
{
    result.push_back(1);
    for (int j= i; j> 0; j--)
    {
        result[j]+= result[j- 1];
    }
}
```
        