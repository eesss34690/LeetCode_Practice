# 16_3Sum_Closest
###### tags: `leetcode` `16`
## Problem Statement
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

- Example 1:

> Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 
- Constraints:

> $3 \leq nums.length \leq 10^3$
$-10^3 \leq nums[i] \leq 10^3$
$-10^4 \leq target \leq 10^4$

## Solution
- The intuitive way is to split the array into half regarding to whether it is below average or above average.
```cpp=
sort(nums.begin(), nums.end());
auto it= lower_bound(nums.begin(), nums.end(), target/ 3);

vector<int> lo(nums.begin(), it);
vector<int> hi(it, nums.end());
```
- If all the number is below or above we can simply return the answer

```cpp=
if (it== nums.begin())
    return nums[0]+ nums[1]+ nums[2];
if (it== nums.end())
    return *(nums.end()- 1)+ *(nums.end()- 2)+ *(nums.end()- 3);
```
- There are 2 possibilities and 1 exception.
```!
a. 2 values from higher and 1 from lower.
```
- Select the value and add up, since the vector is in sorted order, break the loop if the value has exceed the target.
```cpp=
for (auto &i: lo)
{
    for (vector<int>::iterator j= hi.begin(); j!= hi.end()- 1; j++)
    {
        for (vector<int>::iterator k= j+ 1; k!= hi.end(); k++)
        {
            temp= i+ *j+ *k;
            //cout<<i<<" "<< *j<<" "<< *k<<" "<<temp<<endl;
            if (temp> target)
            {
                if (temp-  target< abs(close))
                    close= temp- target;
                break;
            }
            else if (target== temp)
            {
                return target;
            } 
            else if (target- temp< abs(close))
            {
                close= temp- target;
            } 
        }
    }
}
```
```!
b. 2 values from lower and 1 from higher.
```
- Select the value and add up, since the vector is in sorted order, break the loop if the value has below the target.
```cpp=
for (auto &i: hi)
{
    for (vector<int>::iterator j= lo.end()- 1; j!= lo.begin(); j--)
    {
        for (vector<int>::iterator k= j- 1; k- lo.begin()> -1; k--)
        {
            temp= i+ *j+ *k;
            if (temp< target)
                    {
                if (target- temp< abs(close))
                    close= temp- target;
                break;
            }
            else if (target== temp)
            {
                return target;
            } 
            else if (temp- target< abs(close))
            {
                close= temp- target;
            } 
        }
    }
}
```
- The exception is because of the fact that we use ```lower_bound```, so the smallest 3 higher values might be closer to the target.

```cpp=
if (hi.size()> 2)
{
    temp= hi[0]+ hi[1]+ hi[2];
    if (temp- target< abs(close))
        return temp;            
}
```