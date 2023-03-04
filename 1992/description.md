# 1992. Find All Groups of Farmland
###### tags: `leetcode`
## Description
You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is `(0, 0)` and the bottom right corner of land is `(m-1, n-1)`. Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at `(r1, c1)` and a bottom right corner at `(r2, c2)` is represented by the 4-length array `[r1, c1, r2, c2]`.

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.

- Example 1:
![](https://i.imgur.com/RZ9j8Ue.png)

>Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
>>Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].

- Example 2:
![](https://i.imgur.com/cTB8DKW.png)

>Input: land = [[1,1],[1,1]]
Output: [[0,0,1,1]]
>>Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].

- Example 3:
![](https://i.imgur.com/0ajWtfE.png)

>Input: land = [[0]]
Output: []
>>Explanation:
There are no groups of farmland.

- Constraints:

>$m == land.length$
$n == land[i].length$
$1 \leq m, n \leq 300$
land consists of only 0's and 1's.
Groups of farmland are rectangular in shape.

## Solution
- The problem is a simple `DFS`
- By iterating through all the nodes, find the farmland and start the iteration for the farmland. Place the stamp on the extra go through places
```cpp=
if (land[i][j] == 0)
    continue;
int x = i;
int y;
for (; x < land.size() && land[x][j]; ++x) {
    for (y = j; y < land[0].size() && land[x][y]; ++y) {
        land[x][y] = 0;
    }
}
```
- After the iteration, the last index is the final bottom right one. Append it into the answer
```cpp=
groups.push_back({i, j, x - 1, y - 1});
```