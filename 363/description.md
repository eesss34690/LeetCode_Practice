# 363_Max_Sum_of_Rectangle_No_Larger_Than_K
###### tags: `leetcode` `363`
## Problem Statement
Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.

- Example 1:

> Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
- Example 2:

> Input: matrix = [[2,2,-1]], k = 3
Output: 3
 
- Constraints:

> m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-105 <= k <= 105
 
- Follow up: What if the number of rows is much larger than the number of columns?
## Solution
- This is a ```Dynamic Programming``` problem.
- Since it is a 2-D array, first calculate the cumulative summation of the row.

```cpp=
for(int i=0;i<n;i++){
    for(int j=1;j<m;j++)
        matrix[i][j]+=matrix[i][j-1];
        }
```
- The following is to construct the starting point and ending point for columns and calculate each results in the gap.
- In the list of each column completion, sort eacah value and find the closest it can get to destinated ```k``` for the cumulative result.
- And if the gap is small, compare it to the current optimal solution.

```cpp=
for(int start=0;start<m;start++){
    for(int end=start;end<m;end++){
        set<int> s = {0};
        int pref_sum = 0;
        // for current width of rectangle
        for(int i=0;i<n;i++){
            int sum = matrix[i][end];
            if(start>0)
                sum-=matrix[i][start-1];
            pref_sum+=sum;
            auto itr = s.lower_bound(pref_sum-k);
            if(itr!=s.end())
                ans = max(ans,pref_sum-(*itr));
            s.insert(pref_sum);
        }
    }
}
```