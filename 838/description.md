# 838_Push_Dominoes
###### tags: `leetcode` `838`
## Problem Statement
There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

```!
dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.
```
- Example 1:

> Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
- Example 2:

> Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
 
- Constraints:

> $n = dominoes.length$
$1 \leq n \leq 10^5$
dominoes[i] is either 'L', 'R', or '.'
## Solution
- This can be seen by the following pattern
- To begin with, if the domino is pushed, it cannot be push back to other position, so the dominoes which are not '.' would not change
- As for the balanced ones, their status depends on dominoes around. Since the dominoes have sequential effect, the consecutive balanced dominoes can be considered together.

```cpp=
if(dominoes[i]=='.'){
    int j=i-1;
    while(dominoes[i]=='.'){
        i++;
    };
// to be continue
}
```
- Measure the both side would have the following possibilities

|two side|result|
|-|-|
|Both sides has the same push direction|the middle balanced ones all puahed to the direction|
|Both sides push outward|no change|
|Both sides push inward|left half pushed left, right half pushed right|

```cpp=
//1
if(dominoes[i]==dominoes[j]){
    while(j<i){
        ans[++j]=dominoes[i];
    }
}
```
```cpp=
//3
else if(dominoes[i]=='L'){
    int ii=i;
    while(j<(i-2)){
        ans[++j]='R';
        ans[--i]='L';
    }
    i=ii;
}
```