## 315_Count_of_Smaller_Numbers_After_Self
###### tags: `leetcode` `315`
## Problem Statement
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

- Example 1:

> Input: nums = [5,2,6,1]
Output: [2,1,1,0]
- Explanation:
> To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
- Example 2:

> Input: nums = [-1]
Output: [0]
- Example 3:

> Input: nums = [-1,-1]
Output: [0,0]
 

- Constraints:

> 1 <= nums.length <= 105
-104 <= nums[i] <= 104

## Solution
- With the constraits we have, there are 1e5 points at most.

```cpp=
int bit[100001];
```
- We do it by reverse and see whether there is any number smaller in the stored array and add all of them together.

```cpp=
int query(int index){
    int count=0;
    for(;index>0;index-=index&(-index))
        count+=bit[index];
    return count;
}
```
- Update the array for futher use

```cpp=
void update(int index){
    for(;index<=100000;index+=index&(-index))
        bit[index]++;
}
```
- the whole structure
```cpp=
class Solution {
public:
    int bit[100001];
    int offset=1e4+1;
    int n;
    
    void update(int index){
        for(;index<=100000;index+=index&(-index))
            bit[index]++;
    }
    
    int query(int index){
        int count=0;
        for(;index>0;index-=index&(-index))
            count+=bit[index];
        return count;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        n=nums.size();
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            ans[i]=query(nums[i]+offset-1);
            update(nums[i]+offset);
        }
        
        return ans;
    }
};
```