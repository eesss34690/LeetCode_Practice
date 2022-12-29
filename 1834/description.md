# 1834. Single-Threaded CPU
###### tags: `leetcode`
## Problem Statement
You are given `n` tasks labeled from `0` to `n - 1` represented by a 2D integer array tasks, where `tasks[i] = [enqueueTimei, processingTimei]` means that the `ith` task will be available to process at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.

- Example 1:
>Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
>Explanation: The events go as follows: 
> - At time = 1, task 0 is available to process. Available tasks = {0}.
> - Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
> - At time = 2, task 1 is available to process. Available tasks = {1}.
> - At time = 3, task 2 is available to process. Available tasks = {1, 2}.
> - Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
> - At time = 4, task 3 is available to process. Available tasks = {1, 3}.
> - At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
> - At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
> - At time = 10, the CPU finishes task 1 and becomes idle.

- Constraints:
> tasks.length == n
1 <= n <= 105
1 <= enqueueTimei, processingTimei <= 109

## Solution
- Because in the queue we need to sort the upcoming new items into the sorted list, it is resemble to the `priority queue`. Before the iteration, since the answer requires the original sequence, the index should be added and it has the least priority

```cpp=
vector<array<int, 3>> sortedTasks;
for (int i = 0; i < tasks.size(); ++i) {
    sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
}
```
- After sorting the sequence, the queue should be updated when the processing time of the previous task finishs. And to noted, if idle condition is confronted, the time need to be updated
```cpp=
if (nextTask.empty() && currTime < sortedTasks[taskIndex][0]) {
    // When the heap is empty, try updating currTime to next
    // task's enqueue time.
    currTime = sortedTasks[taskIndex][0];
}
while (taskIndex < sortedTasks.size() && currTime >= sortedTasks[taskIndex][0]) {
    nextTask.push({sortedTasks[taskIndex][1], sortedTasks[taskIndex][2]});
    ++taskIndex;
}
```
- Then the first one in the queue should be the next task to be dealed with. So take it out, update the new time, and then remove it