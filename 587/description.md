# 587 Erect the Fence
###### tags: `leetcode` `587`
## Problem Statement
You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.

You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed.

Return the coordinates of trees that are exactly located on the fence perimeter.

- Example 1:
![](https://i.imgur.com/nJVDMXP.png)

> Input: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[3,3],[2,4],[4,2]]
- Example 2:
![](https://i.imgur.com/g7Op1aC.png)

> Input: points = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
 
- Constraints:

> $1 \leq points.length \leq 3000\\
points[i].length = 2\\
0 \leq x_i, y_i \leq 100$
All the given points are unique.
## Solution
- It is a typical question for ```Convex Hull```. Using one point as the starting point and extend for each node and see whether it construct a hole and can be filled up.
- To implement the algorithm, use two of the nodes as the last line.
```cpp=
vector<int> p1 = points[0];
vector<int> p2 = points.back();
```
- For each node, check if it is a hall or it is a spike. 
```cpp=
//spike from beginning checking
if(i == points.size() - 1 || !ccw(p1, points[i], p2)){
    // remove unnecessary points
    while(up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], points[i])){
        up.pop_back();
    }
    // add current point
    up.push_back(points[i]);       
}
//spike check
bool cw(vector<int> a, vector<int> b, vector<int> c){
    return  a[0]*(b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) > 0;
}
```
```cpp=
// spike check from the last point of view
if(i == points.size() - 1 || !cw(p1, points[i], p2)){
    // remove redundant points
    while(down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], points[i])){
        down.pop_back();
    }
    down.push_back(points[i]);
}
//spike backward check
bool cw(vector<int> a, vector<int> b, vector<int> c){
    return  a[0]*(b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) > 0;
}
```
- Then combine the upper check and backward check, use union to see the final result
```cpp=
for(auto i : up){
    points.push_back(i);
}
for(int i = down.size() - 2;i>0;i--){
    points.push_back(down[i]);
}
sort(points.begin(), points.end());
points.resize(unique(points.begin(), points.end()) - points.begin());
```