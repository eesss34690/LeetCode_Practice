# 1235 Maximum Profit in Job Scheduling
###### tags: `leetcode` `1235`
## Problem Statement
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

- Example 1
![](https://i.imgur.com/pYQ2GCs.png)
> Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
- Example 2
![](https://i.imgur.com/ioORdKu.png)
> Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60
- Example 3
![](https://i.imgur.com/Wh1i6Bo.png)
> Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
- Constraints

> $1 \leq startTime.length == endTime.length == profit.length \leq 5 * 10^4\\ 
1 \leq startTime[i] < endTime[i] \leq 10^9\\ 
1 \leq profit[i] \leq 10^4$

## Solution
- The most crucial part of this question is to sort the ```startTime```, ```endTime```, ```profit```.
- To make the correct order, first distinguish the starting time, then the ending time, then the profit
```cpp=
bool static comp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0] && a[1]==b[1]){
        return a[2]<b[2];
    }

    else if(a[1]==b[1]){
        return a[0]<b[0];
    }

    else{
        return a[1]<b[1];
    }
}
```
- To make the pair together, comstruct the vector to compare.
```cpp=
vector<vector<int>>vec(n);

for(int i=0;i<n;i++){

    int a=startTime[i];
    int b=endTime[i];
    int c=profit[i];

    vec[i]={a,b,c};
}
sort(vec.begin(),vec.end(),comp);
```
- With the order, the rest is simply dynamic programming. Use binary search to see the last ending time available for the current starting time to catch on.
```cpp=
while(low<=high){
    int mid=(low+high)/2;

    if(vec[mid][1]<=vec[i][0]){
        inc=mid;
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
```
- Then add the last part up and add to the dp array.
```cpp=
if(inc!=-1){
    ans+=dp[inc];
}
dp[i]=max(ans,dp[i-1]);
```