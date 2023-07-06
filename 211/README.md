# 211. Design Add and Search Words Data Structure
###### tags: `leetcode`
## Description
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

- Example:

>Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]
>>Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

- Constraints:

>$1 \leq word.length \leq 25$
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 3 dots in word for search queries.
At most 104 calls will be made to addWord and search.

## Solution
- The problem is an extension of [208-Trie Tree](https://github.com/eesss34690/LeetCode_Practice/tree/main/208). The main challenge is the `search` that requires the all the matching words.
- To specify the structure for solving the question, construct a `alphalete` struct that holds the next alphalete for all the possibilities and whether it is the last one.
```cpp=
struct alphalete {
    alphalete* next[26];
    bool isLast = false;
};
alphalete* root;
```
- When adding word, iterate through all the characters and add the Node structure if there is no previously declared Node for that position. Switch to the next iterator once finish adding. Put a last stamp on the last character.
```cpp=
alphalete* temp = root;
for (auto &i : word)
{
    if (temp->next[i - 'a'] == NULL)
        temp->next[i - 'a'] = new alphalete();
    temp = temp->next[i - 'a'];
}
temp->isLast = true;
```
- For searching the existence of the string, I used `BFS` at the first time but got `TLE`. After consideration, change to `recursive` solve the problem and get a good performance.
- For the searching pattern, iterate through all the characters in the pattern. When the character is `.`, it opens all the subroute for the searching of the substring. Straightly return true if one of the substring return positive result. If all the substring does not give correct result, return false instead.
```cpp=
if (word[j] == '.') {
    for (auto &c: i->next)
        if (c && searchSubIndex(word, c, j + 1)) return true;
    return false;
}
```
- If the character is a simple alphalete, checck the existece of the Node, iterate next if it exists and return false elsewise
```cpp=
int idx = word[j] - 'a';
if (i->next[idx] == NULL) return false;
i = i->next[idx];
```
- After all the iteration, return if it is the last one
```cpp=
return i->isLast;
```
- The main reason for this to be much faster than `BFS` is that recursive return back once the result is found, which is more similar to `DFS`. While BFS keeps till every iteration goes through.