# 126_Word_Ladder_II
###### tags: `leetcode` `126`
## Problem Statement
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words $beginWord -> s_{1} -> s_{2} -> ... -> s_{k}$ such that:

Every adjacent pair of words differs by a single letter.
Every $s_{i}$ for $1 \leq i \leq k$ is in wordList. Note that beginWord does not need to be in wordList.
$s_{k} = endWord$
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words $[beginWord, s_{1}, s_{2}, ..., s_{k}]$.

- Example 1:

> Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
- Example 2:

> Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 
- Constraints:

> $1 \leq beginWord.length \leq 5$
endWord.length == beginWord.length
$1 \leq wordList.length \leq 1000$
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
## Solution
- This question can be done by using ```BST``` for searching the shortest path.
- The adjacency list is determined by seeing whether the two words have only 1 difference
```cpp=
bool differsByOne(string s, string t) {
    int c=0;
    for(int i=0;i<s.size();i++) {
        if(s[i]!=t[i])  c++;
        if(c>1) break;
    }
    return c==1;
}
```
- To implement BFS, needs...
    - Queue to store the job list.
    - Vector to store whether the string is visited.
    - Since in this question we need to store the answer with string format, some structures are changed.

```cpp=
queue<Pair> q;
q.push({beginWord,{beginWord}});
unordered_map<string, bool> vis;
```
- In the queue keep looking for the adjacency for the target and mark it as ```visited```.

```cpp=
while(!q.empty()) {
    string str=q.front().s;
    vector<string> currAns=q.front().curr;
    q.pop();
        
    vis[str]=1;                                        
    for(int i=0;i<n;i++) {
        if(!vis.count(wordList[i]) && differsByOne(str, wordList[i])) {
            currAns.push_back(wordList[i]);
            q.push({wordList[i], currAns});
            currAns.pop_back();
        }
    }        
}
```
- If the target is ending string, push the answer by the sequence in pair.

```cpp=
if(str==endWord && currAns.size()<=mx) {
    mx=currAns.size();
    ans.push_back(currAns);
} 
```