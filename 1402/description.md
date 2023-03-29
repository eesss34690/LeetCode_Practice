# 1402. Reducing Dishes
###### tags: `leetcode`
## Description
A chef has collected data on the `satisfaction` level of his n dishes. Chef can cook any dish in 1 unit of time.

**Like-time coefficient** of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. `time[i] * satisfaction[i]`.

Return the maximum sum of **like-time coefficient** that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

- Example 1:

>Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
>>Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

- Example 2:

>Input: satisfaction = [4,3,2]
Output: 20
>>Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

- Example 3:

>Input: satisfaction = [-1,-4,-5]
Output: 0
>>Explanation: People do not like the dishes. No dish is prepared.

- Constraints:

>n == satisfaction.length
$1 \leq n \leq 500$
$-1000 \leq satisfaction[i] \leq 1000$

## Solution
- The problem can be done by a back tracking dynamic programming
- In order to get the maximum sum of coefficient, the key point is to `sort` the satisfaction vector first, because it is more likely for the dish in higher satisfaction to exist in the last place
```cpp=
sort(satisfaction.begin(), satisfaction.end());
```
- After sorting, back tracking for each of the dishes for the previous maximum like-time coefficient sum, if there is no dishes yet, check the current one to see whether it is larger than 0. Append it if it is
```cpp=
else if (satisfaction[i] > 0) dp[i] = satisfaction[i];
```
- If the previous sum is larger than 0, it means that there are two options
    - Use the previous one (the current satisfaction added would decrease the result)
    - Add the current one, and the time increase bouns for previous coefficient and the previous one
- It is obvious that for the first case there is no possibility to let the latter dish to appear because the latter contains lower satisfaction ratio. In this case, return back the result
```cpp=
else return dp[i + 1];
```
- Otherwise, update the satisfaction to add on in order to let latter computation add on time effect, and also add the dp
```cpp=
if (satisfaction[i] + dp[i + 1] + satisfaction[i + 1] > dp[i + 1])
{
    dp[i] = satisfaction[i] + dp[i + 1] + satisfaction[i + 1];
    satisfaction[i] += satisfaction[i + 1];
}
```