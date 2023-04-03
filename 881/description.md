# 881. Boats to Save People
###### tags: `leetcode`
## Description
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

- Example 1:

>Input: people = [1,2], limit = 3
Output: 1
>>Explanation: 1 boat (1, 2)

- Example 2:

>Input: people = [3,2,2,1], limit = 3
Output: 3
>>Explanation: 3 boats (1, 2), (2) and (3)

- Example 3:

>Input: people = [3,5,3,4], limit = 5
Output: 4
>>Explanation: 4 boats (3), (3), (4), (5)

- Constraints:

>$1 \leq people.length \leq 5 \times 10^4$
$1 \leq people[i] \leq limit \leq 3 \times 10^4$

## Solution
- The problem can be solved by using two pointers to iterate through answer. This is because there are at most two people in a single boat
- We need to sort the people weight before the iteration because the left and right should be the lightest and the heaviest
```cpp=
sort(people.begin(), people.end());
```
- While iterating, if the lightest (left pointer) plus the heaviest (right pointer) is larger than the limit, add the heaviest one into a boat and move the pointer, else put the two together (which means we move two pointers)
```cpp=
int r = people.size() - 1, l = 0, ans = 0;
while (l < r)
{
    while (people[l] + people[r] > limit && r != l)
        r--, ans++;
    ans++, l++, r--;
}
```
- When returning back, because there is possibility that the iteration ends in the inner loop and the middle one has already been calculated, check the left and right pointer value for final answer
```cpp=
return (l == r) ? ans + 1 : ans;
```