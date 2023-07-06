# 208. Implement Trie (Prefix Tree)
###### tags: `leetcode`
## Description
A trie (pronounced as "try") or **prefix tree** is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

`Trie()` Initializes the trie object.
`void insert(String word)` Inserts the string `word` into the trie.
`boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
`boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

- Example 1:

>Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]
>>Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

- Constraints:

>$1 \leq word.length, prefix.length \leq 2000$
word and prefix consist only of lowercase English letters.
At most $3 \times 10^4$ calls in total will be made to insert, search, and startsWith.

## Solution
- The problem can be solved by using vector, but the time complexity would be bad and the result is low pass for the time constraint
- To better solve this problem, one can use a `Linked Tree` structure to store the string set. Each of the Node connect to all the possibilities of the next characters
```cpp=
struct TrieNode {
    TrieNode* child[26];
    bool hasVal = false;
};
```
- When doing insertion, check the existence of the next node and construct it if it does not exist. Shift to the next index in order to do the treversal
```cpp=
auto cur = root;
for (auto &i : word)
{
    if (cur->child[i - 'a'] == NULL)
        cur->child[i - 'a'] = new TrieNode();
    cur = cur->child[i - 'a'];
}
```
- When it is the last one, put a stamp in order to remember the all string shape
```cpp=
cur->hasVal = true;
```
- When doing searching and checking the start with, go through the Tree structure and check the existence of the node, return false if there is no current word.
- The different between searching and checking is that the searching requires the character to be the last one if it is the end of the search, Therefore, return the stamp of the last value
```cpp=
auto cur = root;
for (auto &i : word)
{
    if (cur->child[i - 'a'] == NULL) return false;
    cur = cur->child[i - 'a'];
}
return cur->hasVal;
```
