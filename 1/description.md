# 1_Two_Sum
###### tags: `leetcode` `827`
## Problem Statement
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
- Example 1:

> Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
- Example 2:

> Input: nums = [3,2,4], target = 6
Output: [1,2]
- Example 3:

> Input: nums = [3,3], target = 6
Output: [0,1]
 
- Constraints:

> $2 \leq nums.length \leq 10^4 \\
-10^9 \leq nums[i] \leq 10^9 \\
-10^9 \leq target \leq 10^9$
Only one valid answer exists.
## Solution
- Since it needs to find the 2 sum that matches the target, we can emplace a map to natch its corresponding value and position.

```cpp=
for (int i= 0; i< si; i++)
{
    sor.emplace(nums[i], i);
}
```
- By looking into each word to search for their match and see whether it exists.

```cpp=
int val= target- i.first;
auto fi= sor.find(val);
```
- There are 2 posibilities to find the corresponding answer.
    - The number is exactly half of the target and it found the same number in the set.
    - The number is the answer.
- We need to deal with the first scenario by looking for the next half target. If it does not exist, it means it is not a valid pair.

```cpp=
if (fi!= sor.end())
{
    if (fi->first== i.first)
    {
        nums[i.second]= INT_MAX;
        auto look= find(nums.begin(), nums.end(), i.first);
        if (look!= nums.end())
        {
            int an= look- nums.begin();
            return {an, i.second};
        }
        else
            continue;
    }
    return {fi->second, i.second};
}
```
