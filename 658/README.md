# 658_Find_K_Closest_Elements
###### tags: `leetcode` `658`
## Problem Statement
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
:::info
An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
:::

- Example 1:

> Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
- Example 2:

> Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 
- Constraints:

> 1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

## Solution
- This can be done by ```binary search```
- First find the closest value in the array for the designated one
- Set the left and right bound and add the cloest to the solution
```python=
dist= [abs(i- x) for i in arr]
r= dist.index(min(dist))+ 1
l= r- 2
a= [arr[r- 1]]
```
- Then keep on adding values for the rest
- If one of the bound is out, add the rest in the bound and leave the loop

```python=
 if r== len(arr):
    for j in range(k- i- 1):
    a.append(arr[l- j])
break
if l== -1:
    for j in range(k- i- 1):
        a.append(arr[r+ j])
break
```
- Else it is the normal situation, add the right value if hte distance is smaller, else is left.

```python=
if dist[r]< dist[l]:
    a.append(arr[r])
    r= r+ 1
else:
    a.append(arr[l])
    l= l- 1
```