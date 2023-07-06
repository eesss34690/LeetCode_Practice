# 331 Verify Preorder Serialization of a Binary Tree
###### tags: `leetcode` `331`
## Problem Statement
One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.
![](https://i.imgur.com/u8IMOzj.png)
For example, the above binary tree can be serialized to the string $"9,3,4,#,#,1,#,#,2,#,6,#,#"$, where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is **guaranteed** that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always **valid**.

For example, it could never contain two consecutive commas, such as "1,,3".
Note: You are not allowed to reconstruct the tree.

 

- Example 1:

> Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
- Example 2:

> Input: preorder = "1,#"
Output: false
- Example 3:

> Input: preorder = "9,#,#,1"
Output: false
 

- Constraints:

> $1 \leq preorder.length\leq 10^4$
preorder consist of integers in the range [0, 100] and '#' separated by commas ','
## Solution
- At first I was just simply want to build a correct solution, the first thought of mine was to construct the vector for the string
```cpp=
auto pos= preorder.find(",");
while (1)
{
    temp.push_back(preorder.substr(0, pos));
    if (pos== string::npos)
        break;
    preorder= preorder.substr(pos+ 1, string::npos);
    pos= preorder.find(",");
}
```
- Then with the string, we can know that for each non-null node, it needs two children, therefore it is a simple queue issue.
- To notice, the reason for failure is that when we need siblings, there is nothing left.
```cpp=
queue<string> waiting;
waiting.push(temp[0]);
while (!waiting.empty())
{
    target= waiting.front();
    waiting.pop();
    if (target!= "#")
    {
        if (ind+ 2< temp.size())
        {
            waiting.push(temp[++ind]);
            waiting.push(temp[++ind]);
        }
        else
            return false;
    }
}
```
- After finishing, check whether it is actually the last one.
```cpp=
if (ind== temp.size()- 1)
    return true;
return false;
```