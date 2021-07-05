# 274_H_Index
###### tags: `leetcode` `274`
## Problem Statement
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

- Example:

> Input: citations = [3,0,6,1,5]
> Output: 3 
> Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. 
> Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, her h-index is 3.

- Note: If there are several possible values for h, the maximum one is taken as the h-index.

## Solution
- Since there are problem related to element size, sort the array first
```cpp=
sort(citations.begin(), citations.end());
```
- According to the statement, there are ```h``` elements at least ```h```, split the array into ```N-h``` and ```h``` and then check whether the middle fits the condition.
```cpp=
for (int i= citations.size(); i> 0 ; i--)
{
    if (citations[citations.size()- i]>= i)
    {
        return i;
    }
}
```
- If no one fits, return 0
