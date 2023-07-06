# 300_Longest_Increasing_Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

- Example 1:

> Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
- Example 2:

> Input: nums = [0,1,0,3,2,3]
Output: 4
- Example 3:

> Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
- Constraints:

> 1 <= nums.length <= 2500
-104 <= nums[i] <= 104
## Solution
- Because it wants to find the ```subsequence```, which means that the order is also important. The former can be replaced if te value is bigger, which may affect the latter sequence.
- The problem can be seen as to find wether the value now is bigger than the last of sequence.
    - If yes, simpily add in the last one.
    - Otherwise, search where is the gap of the sequence for the value and replace the smaller one.

```cpp=
if (i< ans[size])
{
    l= 0, r= size;
    while(l< r)
    {
        m=(l+ r)/ 2;
        if (ans[m]< i)
            l= m+ 1;
        else
            r= m;
    }
    ans[l]= i;
}
else if (i!= ans[size])
{
    ans[++size]= i;
}
```