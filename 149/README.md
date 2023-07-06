# 149. Max Points on a Line
###### tags: `leetcode`
## Problem Statement
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

- Example 1:
![](https://i.imgur.com/yclS45D.png)

>Input: points = [[1,1],[2,2],[3,3]]
Output: 3

- Example 2:
![](https://i.imgur.com/Js5D28O.png)

>Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4

- Constraints:

>1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

## Solution
- This is a task that needs to be complemented by a map
- The line is determined by the slope of the two dots. As the result, get the slope of the lines and calculate the maximum accumulated slopes
```cpp=
double x2 = it2[0], y2 = it2[1];
double slope;
if(x2 - x1 == 0){
    slope = INT_MAX;
}else{
    slope = (y2 - y1) / (x2 - x1);   
}
mp[slope]++;
ans = max(ans, mp[slope]);
```