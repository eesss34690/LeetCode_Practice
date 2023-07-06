# 2215. Find the Difference of Two Arrays
###### tags: `leetcode`
## Description
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

- Example 1:

>Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
>>Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

- Example 2:

>Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
>>Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

- Constraints:

>$1 \leq nums1.length, nums2.length \leq 1000$
$-1000 \leq nums1[i], nums2[i] \leq 1000$

## Solution
- Use two sets to store the distinct value for the answer and put everything inside it
```cpp=
unordered_set<int> n1, n2;
for (auto &i : nums1) n1.insert(i);
for (auto &i : nums2) n2.insert(i);
```
- Then iterate through one of the set and check the existence in another one. Put in the value if the other set does not have it. Elsewise delete the one in the another set to disinclude it
```cpp=
for (auto &i : n2)
{
    if (n1.count(i) == 0) ans[1].push_back(i);
    else n1.erase(i);
}
```
- Then the rest in the rest set should be put in the answer
```cpp=
for (auto &i : n1) ans[0].push_back(i);
```
