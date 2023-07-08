# 429_N-ary_Tree_Level_Order_Traversal
###### tags: `leetcode` `429`
## Problem Statement
Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
- Example 1:
![](https://i.imgur.com/FZwzqNy.png)
> Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
- Example 2:
![](https://i.imgur.com/TF7ZKNa.png)
> Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 
- Constraints:

> The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between $[0, 10^4]$
## Solution
- This problem is a simple level order treversal.
- In typical manner, push the root into a queue and start trevering
```cpp=
queue.push_back(root);
levelAdd(1);
```
- The construction of treversal is to seek the whole queue with the legitimate amount and put them in the same level
```cpp=
for (int i= 0; i< size; i++)
{
    Node* now= queue[0];
    queue.erase(queue.begin());
    a.push_back(now->val);
    queue.insert(queue.end(), (now->children).begin(), (now->children).end());
    n+= (now->children).size();
}
```
- Remember to add the new one into the waiting queue and implement the size