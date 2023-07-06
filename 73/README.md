# 73_Set_Matrix_Zeroes
###### tags: `leetcode` `73`
## Problem Statement
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

- Example 1:
![](https://i.imgur.com/nSUNljO.png)
> Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
- Example 2:
![](https://i.imgur.com/AXb5oGU.png)

> Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 
- Constraints:

> $m = matrix.length\\
n = matrix[0].length\\
1 \leq m, n \leq 200\\
-2^{31} \leq matrix[i][j] \leq 2^{31} - 1$
## Solution
- Since this needs to be done ```inplace```, we need to use a significant mark as to record the column and row value.
- Because the first row and the first column are the specific one and using 0 as indicator may lead to misjudge, the first needs to be considered first.
- Using the boolean to record whether the row is to be clean or the column is.
```cpp=
bool onfirstRow = false,onfirstCol = false;
for(int j=0;j<m;j++){
    if(!matrix[0][j]){
        onfirstRow = true;
        break;
    }
}
for(int i=0;i<n;i++){
    if(!matrix[i][0]){
        onfirstCol = true;
        break;
    }
}
```
- For doing this, regulate the first column and the first row as the mark position. Mark it as ```0``` when there is one 0 in column/ row.
```cpp=
for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
        if(!matrix[i][j])
            matrix[i][0] = matrix[0][j] = 0;
    }
}
```
- The final problem is that to replace all the value in between as 0. Do it with the value in the middle first then use the boolean to get the first two done.

```cpp=
for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
        if(!matrix[i][0] or !matrix[0][j])
            matrix[i][j] = 0;
    }
}
if(onfirstRow){
    for(int j=0;j<m;j++)
        matrix[0][j] = 0;
}
if(onfirstCol){
    for(int i=0;i<n;i++)
        matrix[i][0] = 0;
}
```