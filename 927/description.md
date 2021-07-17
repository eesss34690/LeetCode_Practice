# 927_Three_Equal_Parts
###### tags: `leetcode` `927`
## Problem Statement
You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.

If it is possible, return any $[i, j]$ with $i + 1 < j$, such that:

```
arr[0], arr[1], ..., arr[i] is the first part,
arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
All three parts have equal binary values.
```
If it is not possible, return [-1, -1].

Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

- Example 1:

> Input: $arr = [1,0,1,0,1]$
Output: $[0,3]$
- Example 2:

> Input: $arr = [1,1,0,1,1]$
Output: $[-1,-1]$
- Example 3:

> Input: $arr = [1,1,0,0,1]$
Output: $[0,2]$
 
- Constraints:

> $3 \leq arr.length \leq 3 * 10^4$
$arr[i]$ is 0 or 1
## Solution
- Since there are a lot of difference allowance for 0, the best way is to record the **1** in the vector.

```cpp=
for(int i= 0; i< arr.size(); i++)
{
    if(arr[i])
        ind.push_back(i);
}
```
- Because there ar 3 slices, the number of 1 must be the multiple of 3.

```cpp=
if (ind.size()% 3)
    return ans;
```
- If there is no **1**, it can be sliced in any form.

```cpp=
if (!ind.size())
{
    ans[0]= arr.size()/ 3- 1;
    ans[1]= arr.size()- 1;
    return ans;
}
```
- Split the vector by 1 with the index.

```cpp=
int por= ind.size()/ 3;
int a= ind[0], b= ind[por], c= ind[por* 2];
```
- If the Because the last one cannot add more 0, use it as the regulation and slice the others.

```cpp=
vector<int> three(c+ arr.begin(), arr.end());
int d= three.size();
vector<int> one(a+ arr.begin(), a+ d+ arr.begin());
vector<int> two(b+ arr.begin(), b+ d+ arr.begin());
```
- Compare the slice and make action.

```cpp=
if (one== two&& one== three)
{
    ans[0]= a+ d- 1;
    ans[1]= b+ d;
}
```