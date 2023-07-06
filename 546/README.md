# 546_Remove_Boxes
###### tags: `leetcode` `546`
## Problem Statement
You are given several boxes with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.

Return the maximum points you can get.

- Example 1:

> Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
- Example 2:

> Input: boxes = [1,1,1]
Output: 9
- Example 3:

> Input: boxes = [1]
Output: 1
- Constraints:

> $1 \leq boxes.length \leq 100\\
1 \leq boxes[i] \leq 100$
## Solution
- It is a hard question. The first thought of mine is to use ```DFS``` but the construction of DFS in this is relatively hard.
- The next algorithm may ne possible is to use ```dynamic programming```. During each step can be split in a clearer way.
- To begin with, since using the consecutive be deleted can make extra points with power, We can seperate the question by the formulas.
```!
dp[l][r][k]= how many extra k can get in range l~r to let the #k added to l
```
- Therefore, the whole string can be separated by using the strategy.
```cpp=
while (l+1 <= r && boxes[l] == boxes[l+1]) { 
    l += 1;
    k += 1;
}
int ans = (k+1) * (k+1) + dp(boxes, l+1, r, 0);
for (int m = l + 1; m <= r; ++m)
    if (boxes[m] == boxes[l])
        ans = max(ans, dp(boxes, m, r, k+1) + dp(boxes, l+1, m-1, 0));
```