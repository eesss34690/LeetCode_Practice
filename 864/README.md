# 864. Shortest Path to Get All Keys
###### : `leetcode`
## Description
You are given an m x n grid grid where:

'.' is an empty cell.
'#' is a wall.
'@' is the starting point.
Lowercase letters represent keys.
Uppercase letters represent locks.
You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys. If it is impossible, return -1.

- Example 1:
![](https://assets.leetcode.com/uploads/2021/07/23/lc-keys2.jpg)

>Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
>>Explanation: Note that the goal is to obtain all the keys not to open all the locks.

- Example 2:
![](https://assets.leetcode.com/uploads/2021/07/23/lc-key2.jpg)

>Input: grid = ["@..aA","..B#.","....b"]
Output: 6

- Example 3:
![](https://assets.leetcode.com/uploads/2021/07/23/lc-keys3.jpg)

>Input: grid = ["@Aa"]
Output: -1

- Constraints:

>m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either an English letter, '.', '#', or '@'.
The number of keys in the grid is in the range [1, 6].
Each key in the grid is unique.
Each key in the grid has a matching lock

## Solution
- The problem can be done by using `BFS`
- To begin with, initialize the state and calculate the total number of keys for the presence
```cpp=
int x = -1, y = -1, totalKeys = 0;
for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].length(); j++) {
        if (grid[i][j] >= 'a' && grid[i][j] <= 'f') totalKeys++;
        else if (grid[i][j] == '@')
        {
            x = i;
            y = j;
        }
    }
}
```
- We define a structure called `State`, with key value and its key position. The key iss constructed with binary representation
```cpp=
struct State {
    int keys, i, j;
    State(int keys, int i, int j) : keys(keys), i(i), j(j) {}
};
```
- For the queue, put the State information with starting point. Also insert the visited value for the recognition whether it has been iterated through
```cpp=
State start(0, x, y);
queue<State> q;
unordered_set<string> visited;
visited.insert(to_string(0) + " " + to_string(x) + " " + to_string(y));
q.push(start);
```
- For each position, we check each direction for the presence. Return the step if the current key is the last one
```cpp=
if (cur.keys == (1 << totalKeys) - 1) return step;
for (auto dir : dirs)
{
    i = cur.i + dir[0];
    j = cur.j + dir[1];
    keys = cur.keys;
```
- If it is inside the boundary, check the wall condition, key condition, or lock condition
    - If it is a key, remember it with new binary bit inside
    - If it is a lock, check the presence for the current key by checking the corresponding bit position
```cpp=
if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size())
{
    if (grid[i][j] == '#') continue;
    if (grid[i][j] >= 'a' && grid[i][j] <= 'f') keys |= 1 << (grid[i][j] - 'a');
    if (grid[i][j] >= 'A' && grid[i][j] <= 'F' && ((keys >> (grid[i][j] - 'A')) & 1) == 0) continue;
```
- If all of them failed to meet, it is one of the path we need to go through if the path is not visited yet
```cpp=
if (visited.find(to_string(keys) + " " + to_string(i) + " " + to_string(j)) == visited.end())
{
    visited.insert(to_string(keys) + " " + to_string(i) + " " + to_string(j));
    q.push(State(keys, i, j));
}
```
- Remember to update the step for the value
```cpp=
step++;
```
