# 899 Orderly Queue
###### tags: `leetcode` `1629`
## Problem Statement
You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..

Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

- Example 1:

> Input: s = "cba", k = 1
Output: "acb"
Explanation: 
In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".
- Example 2:

> Input: s = "baaca", k = 3
Output: "aaabc"
Explanation: 
In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".
 
- Constraints:
> $1 \leq k \leq s.length \leq 1000$
s consist of lowercase English letters
## Solution
- It seems to be diffucult, but it is actually related to ```bubble sort```. If we have 2 or more options to shift place, it is bound to get the optimal solution.
- The only one to consider is when ```k==1```, which means that you can only use the first one to the last. Therefore the sequence cannot be modified.
- To get the optimal one, find the minimum of the sequence with different shift.

```cpp=
if(k==1){
    string ans = s;
    for(int i=0;i<s.length();i++){
        ans = min(ans,s.substr(i)+s.substr(0,i));
    }
    return ans;
}
sort(s.begin(),s.end());
```