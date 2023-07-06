## Description
You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.

- Example 1:

>Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
>>Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.

- Example 2:

>Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
Output: 0
>>Explanation: All the elements are already equal, so no operations are needed.

- Constraints:

>n == nums.length == cost.length
1 <= n <= 105
1 <= nums[i], cost[i] <= 106

## Solution
- The problem is difficult to find a suitable algorithm to solve. But if we think intuitively, the problem is related to a `curve` of final modification when it comes to change different target value
    - Consequently, the answer should be the smallest one in the curve
- Because we need to find the finite gap between the possible solution to construct the curve, find the largest and smallest value in the array
```cpp=
int minele = INT_MAX, mxele = INT_MIN, mid;
for (auto &i : nums)
{
    minele = min(minele, i);
    mxele = max(mxele, i);
}
```
- For finding the true value, we can use binary search and narrow down the possible gap for answer
- For each iteration, calculate the current solution for the middle target
```cpp=
mid = minele + (mxele - minele) / 2;
temp = find_cost(nums, cost, mid);
ans = min(ans, temp);
```
- For changing to smaller gap, calculate the ones on the left and right. Use the smaller one as the target gap in the next iteration
```cpp=
r = find_cost(nums, cost, mid + 1);
l = find_cost(nums, cost, mid - 1);
if(temp < l && temp < r) return ans;
else if(temp < l && temp > r) minele = mid + 1;
else mxele = mid - 1;
```