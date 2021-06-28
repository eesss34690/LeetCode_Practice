# 1300_Sum_of_Mutated_Array_Closest_to_Target
###### tags: `leetcode` `1300`
## Problem Statement
Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

- Example 1:

> Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
- Example 2:

> Input: arr = [2,3,5], target = 10
Output: 5
- Example 3:

> Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361

- Constraints:

> 1 <= arr.length <= 104
1 <= arr[i], target <= 105

## Solution
- The array can be accumulated and gradually fit the target by getting down the array number one by one.
- Since the number is substracted if it is bigger than the threshold, the number should be inspect by descending order.
- See if the bigger numbers substracted to the next smaller value fit the need of target.
```cpp=!
sum-= (arr.size()- i)* (arr[i]- arr[i- 1]);
```
- If the target is close enough and the gap is smaller than adding 1, return the result.

```cpp=
if (target>= sum&& target- sum< (arr.size()- i)/2)
{
    return arr[i- 1];
}
```
- If the above condition does not match and the target is bigger than the substraction value, start adding value to fit the goal.

```cpp=
else if (target> sum)
{
    int j= (target- sum)/ (arr.size()- i);
    if (target- sum- j* (arr.size()- i)> (arr.size()- i)/ 2)
        j++;
    return arr[i- 1]+ j;
}
```
- If the result is still bigger but the difference for further substracting the value by 1 cannot be closer to the need now, return the answer.

```cpp=
else if (sum- target< arr.size()- i)
{
    return arr[i- 1];
}
```
- If the above still cannot meet, it means all the values in the array are too big. Straightly get the mean value for the target and return the answer.

```cpp=
if (target- (target/ arr.size())* arr.size()> arr.size()/ 2)
    return target/ arr.size()+ 1;
return target/ arr.size();
```