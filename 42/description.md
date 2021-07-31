# 42_Trapping_Rain_Water
###### tags: `leetcode` `42`
## Problem Statement
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

- Example 1:
![](https://i.imgur.com/QWOWS8e.png)
> Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
- Example 2:

> Input: height = [4,2,0,3,2,5]
Output: 9
 
- Constraints:

> n == height.length
$0 \leq n \leq 3 * 10^4 \\
0 \leq height[i] \leq 10^5$
## Solution
- This question seems to be difficult, but can be solved by easy logic.
- Because we are storing water ```in the middle```, which means that the process can start from the both sides.
```cpp=
int ans = 0,l = 0,r = height.size()-1,l_max = 0,r_max = 0;
```
- Update the 2 sides maximum in each round.
```cpp=
l_max = max(l_max , height[l]);
r_max = max(r_max , height[r]);
```
- Therefore, if one of the side is smaller, it means that this side can be add up water according to the bound at its side.
- After the update, shift the bound to the next round.
```cpp=
if(l_max<r_max)
    ans+=l_max-height[l],l++;
else
    ans+=r_max-height[r],r--;
```