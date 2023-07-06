# 2244. Minimum Rounds to Complete All Tasks
###### tags: `leetcode`
## Problem Statement
You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

- Example 1:
>Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
>>Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.

- Example 2:
>Input: tasks = [2,3,3]
Output: -1
>>Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.

- Constraints:
>$1 \leq tasks.length \leq 105$
$1 \leq tasks[i] \leq 10^9$

## Solution
- Because all the numbers can be composed by 2 and 3 except 1, sort the sequence first and check the occurance of only once
```cpp=
sort(tasks.begin(), tasks.end());
if (tasks.size() == 1)
    return -1;
```
- If it comtains multiple times, get the minimum composition by divided by 3
```cpp=
for (int i = 1; i < tasks.size(); i++)
{
    if (cur != tasks[i])
    {
        if (cnt == 1)
            return -1;
        ans += ((cnt - 1) / 3) + 1;
        cur = tasks[i];
        cnt = 1;
    } else
        cnt++;
}
if (cnt == 1)
    return -1;
ans += ((cnt - 1) / 3) + 1;
return ans;
```