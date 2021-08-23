# 850_Rectangle_Area_II
###### tags: `leetcode` `850`
## Problem Statement
We are given a list of (axis-aligned) rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] , where ```(xi1, yi1)``` are the coordinates of the bottom-left corner, and ```(xi2, yi2)``` are the coordinates of the top-right corner of the ith rectangle.

Find the total area covered by all rectangles in the plane. Since the answer may be too large, return it modulo $10^9 + 7$

- Example 1
![](https://i.imgur.com/wChqi7j.png)
> Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: As illustrated in the picture.
- Example 2
> Input: rectangles = [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is $10^{18}$ modulo $(10^9 + 7)$, which is $(10^9)^2 = (-7)^2 = 49$

- Constraints:

> $1 \leq rectangles.length \leq 200\\ 
rectanges[i].length = 4\\ 
0 \leq rectangles[i][j] \leq 10^9$
The total area covered by all rectangles will never exceed $2^{63} - 1$ and thus will fit in a 64-bit signed integer.
## Solution
- Do this straight forward, shift with order and see in each x, how many volumn is added in y.
- To implement this needs to sort the rectangle first.
```cpp=
set<int> x,y;ll ans = 0;
for(auto v:rectangles){
    x.insert(v[0]);x.insert(v[2]);
    y.insert(v[1]);y.insert(v[3]);
}
```
- Remember the order with ```map```.
```cpp=
int index = 0; 
unordered_map<int,int> coord_x,coord_y;
for(auto it:x){
    coord_x[it] = index++;
}
index = 0;
for(auto it:y){
    coord_y[it] = index++;
}
```
- Since it is possible for overlapping, need to remember the sequence visit record. Also copy the set value.
```cpp=
vector<int> x_val(x.begin(),x.end());
vector<int> y_val(y.begin(),y.end());
vector<vector<bool>> vis(x.size(),vector<bool>(y.size(),false));
```
- Do the modulo first can save time and overload computation, go through one by one and add the volumn
```cpp=
for(auto v:rectangles){
    for(auto start_x=coord_x[v[0]];start_x<coord_x[v[2]];start_x++){
        for(auto start_y=coord_y[v[1]];start_y<coord_y[v[3]];start_y++){
            if(!vis[start_x][start_y]){
                ll width = x_val[start_x+1] - x_val[start_x];
                ll height = y_val[start_y+1] - y_val[start_y];;
                ans = (ans + (width*height)%MOD)%MOD;
            }
            vis[start_x][start_y] = true;
        }
    }
}
```