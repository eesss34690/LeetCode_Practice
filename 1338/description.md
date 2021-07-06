# 1338_Reduce_Array_Size_to_The_Half
###### tags: `leetcode` `1338`
## Problem Statement
Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

- Example 1:

> Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.
- Example 2:

> Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
- Example 3:

> Input: arr = [1,9]
Output: 1
- Example 4:

> Input: arr = [1000,1000,3,7]
Output: 1
- Example 5:

> Input: arr = [1,2,3,4,5,6,7,8,9,10]
Output: 5

- Constraints:

> 1 <= arr.length <= 10^5
arr.length is even.
1 <= arr[i] <= 10^5
## Solution
- This problem need to calculate the frequencies for all the number in the array.
- A unordered map is faster than a normal map and in this case we do not need the order, so use unordered one.
```cpp=
unordered_map<int, int> cnt;
for (int x : arr) ++cnt[x];
```
- Then put the frequencies calculated into a vector and sort out.

```cpp=
for (auto [_, freq] : cnt) fre.push_back(freq);
sort(fre.begin(), fre.end());
```
- One by one eliminates the numbers from the one with the highest frequencies and add up to see the distance between the size.

```cpp=
while (removed < half) {
    ans ++;
    removed += fre[i--];
}
```