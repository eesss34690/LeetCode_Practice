# 954_Array_of_Doubled_Pairs
###### tags: `leetcode` `954`
## Problem Statement
Given an array of integers arr of even length, return true if and only if it is possible to reorder it such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2.
- Example 1:

> Input: arr = [3,1,3,6]
Output: false
- Example 2:

> Input: arr = [2,1,2,6]
Output: false
- Example 3:

> Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
- Example 4:

> Input: arr = [1,2,4,16,8,4]
Output: false
- Constraints:
> $0 \leq arr.length \leq 3 \times 10^4$
arr.length is even.
$-10^5 \leq arr[i] \leq 10^5$
## Solution
- Since the question has lots of exceptions, the best way to deal with it is to use a map to record the occurance of number
```cpp=
unordered_map<int, int> freq;
for (auto num : arr) freq[num]++;
```
- After sorting the order, delete the pair just like playing ghost card.
```cpp=
sort(arr.begin(), arr.end());
        
for (auto num : arr) {
    if (freq[num] && freq[num*2]) {
        freq[num]--;
        freq[num*2]--;
    }
}
```
- Therefore, the only possibility is to have no element left

```cpp=
for (auto [a, b] : freq)
    if (b) return false;
        
return true;
```