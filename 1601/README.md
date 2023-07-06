# 1601. Maximum Number of Achievable Transfer Requests
###### tags: `leetcode`
## Description
We have n buildings numbered from 0 to n - 1. Each building has a number of employees. It's transfer season, and some employees want to change the building they reside in.

You are given an array requests where requests[i] = [fromi, toi] represents an employee's request to transfer from building fromi to building toi.

All buildings are full, so a list of requests is achievable only if for each building, the net change in employee transfers is zero. This means the number of employees leaving is equal to the number of employees moving in. For example if n = 3 and two employees are leaving building 0, one is leaving building 1, and one is leaving building 2, there should be two employees moving to building 0, one employee moving to building 1, and one employee moving to building 2.

Return the maximum number of achievable requests.

- Example 1:
![](https://assets.leetcode.com/uploads/2020/09/10/move1.jpg)

>Input: n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
Output: 5
>>Explantion: Let's see the requests:
From building 0 we have employees x and y and both want to move to building 1.
From building 1 we have employees a and b and they want to move to buildings 2 and 0 respectively.
From building 2 we have employee z and they want to move to building 0.
From building 3 we have employee c and they want to move to building 4.
From building 4 we don't have any requests.
We can achieve the requests of users x and b by swapping their places.
We can achieve the requests of users y, a and z by swapping the places in the 3 buildings.

- Example 2:
![](https://assets.leetcode.com/uploads/2020/09/10/move2.jpg)

>Input: n = 3, requests = [[0,0],[1,2],[2,1]]
Output: 3
>>Explantion: Let's see the requests:
From building 0 we have employee x and they want to stay in the same building 0.
From building 1 we have employee y and they want to move to building 2.
From building 2 we have employee z and they want to move to building 1.
We can achieve all the requests.

- Example 3:

>Input: n = 4, requests = [[0,3],[3,1],[1,2],[2,0]]
Output: 4

- Constraints:

>1 <= n <= 20
1 <= requests.length <= 16
requests[i].length == 2
0 <= fromi, toi < n

## Solution
- We can use `back tracking` machanism for the problem
- To define the problem, we need to use brute force to find all the possibilities, (I initially tried greedy algorithm but the result is incorrect). In order to do so, we can see each of the shift as `to replace, or not replace`
- Define a vector to store the `move in& out` value for each building
```cpp=
vector<int> in(n);
```
- For each possibility, the `move out` is to substract, and the `move in` is to add. Iterate through all the choices with the two options.
```cpp=
in[requests[start][0]]--;
in[requests[start][1]]++;
maxReq(requests, in, start + 1, n, cnt + 1);
in[requests[start][0]]++;
in[requests[start][1]]--;
maxReq(requests, in, start + 1, n, cnt);
```
- Everytime after finishing, check whether the combination is possible. If it is, select the answer to be the maximum of all
```cpp=
if (start == requests.size())
{
    for (int i = 0; i < n; i++)
        if (in[i] != 0) return;
    ans = max(ans, cnt);
}
```
