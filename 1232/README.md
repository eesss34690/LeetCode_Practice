# 1232. Check If It Is a Straight Line
###### tags: `leetcode`
## Description
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

- Example 1:
![](https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg)

>Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

- Example 2:
![](https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg)

>Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

- Constraints:

>2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

## Solution
- The problem needs to handle the case where the tilt is a straight line because the straight line does not contain the tilt value, which is INF
```cpp=
if (coordinates[1][0] - coordinates[0][0] == 0)
{
    for (int i = 2; i < coordinates.size(); i++)
        if (coordinates[i][0] != coordinates[i - 1][0]) return false;
    return true;
}
```
- For the others, calculate the tilt and then check all the affinity tilt value. Return false if the values does not keep the same
```cpp=
float tilt = float(coordinates[1][1] - coordinates[0][1]) / float(coordinates[1][0] - coordinates[0][0]);
for (int i = 2; i < coordinates.size(); i++)
{
    if (float(coordinates[i][1] - coordinates[i - 1][1]) / float(coordinates[i][0] - coordinates[i - 1][0]) != tilt) return false;
}
return true;
```
