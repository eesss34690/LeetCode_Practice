# 275_H_Index_II
###### tags: `leetcode` `275`
## Problem Statement
Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

- Example:

> Input: citations = [0,1,3,5,6]
> Output: 3 
> Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, her h-index is 3.

- Note:

> If there are several possible values for h, the maximum one is taken as the h-index.

- Follow up:

> This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
> Could you solve it in logarithmic time complexity?

## Solution
- I use ```binary search``` solution with ```higher bound``` and ```lower bound```.
```cpp=
int s= citations.size(), h= s, l= 0, m;
```
- The condition for sustaining the searching is that the number in the array in the position of the contrary of the index should not be less than the original value.
- Once the condition is satisfied, move the lower bound as the condition
- Otherwise, shift the upper bound
```cpp=
while (l< h)
{
    m= (h+ l+ 1)/ 2;
    if (m<= citations[s- m])
        l= m;
    else
        h= m- 1;
}
```
- After the lower and upper bound meet, return the last lower bound as the answer.
```cpp=
return l;
```