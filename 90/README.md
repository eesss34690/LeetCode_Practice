# 90_Subsets_II
###### tags: `leetcode` `90`
## Problem Statement
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
- Example 1:

> Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
- Example 2:

> Input: nums = [0]
Output: [[],[0]]
 
- Constraints:

> $1 \leq nums.length \leq 10\\
-10 \leq nums[i] \leq 10$
## Solution
- This is a recursive question.
- To find all the combinations, mathematically it means half of the value with the value added and half not.
- To accomplish this, just revise back the vector to store the answer with new value added if this is a new one.

```cpp=
 for (auto num : nums) {
    size = res.size();
            
    for (int i = 0; i < size; i++) {
        curr = res[i];
        curr.push_back(num);
        if (find(res.begin(), res.end(), curr) == res.end())
            res.push_back(curr);
    }
}
```