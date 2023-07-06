# 118_Pascal's_Triangle
###### tags: `leetcode` `118`
## Problem Statement
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

![](https://i.imgur.com/Npmny7V.png)

In Pascal's triangle, each number is the sum of the two numbers directly above it.

- Example:

> Input: 5
> Output:
> [
>      [1],
>     [1,1],
>    [1,2,1],
>   [1,3,3,1],
>  [1,4,6,4,1]
> ]
## Solution
- Just a simple math, use 2 layers as the for loop condition
```cpp=
vector<vector<int>> result;
for (int i= 0; i< numRows; i++)
{
    vector<int> ele(i+ 1, 1); // all the elements 1
    for (int j= 1; j< i; j++)
    {
        ele[j]= result[i- 1][j- 1]+ result[i- 1][j]; //addition from the former layer
    }
    result.push_back(ele);
}
return result;
```

