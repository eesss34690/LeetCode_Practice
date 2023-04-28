# 839. Similar String Groups
###### tags: `leetcode`
## Description
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

- Example 1:

>Input: strs = ["tars","rats","arts","star"]
Output: 2

- Example 2:

>Input: strs = ["omv","ovm"]
Output: 1

- Constraints:

>$1 \leq strs.length \leq 300$
$1 \leq strs[i].length \leq 300$
`strs[i]` consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other.

## Solution
- The problem can be done by Union Set (A rarely occurred algorithm that is easily forgotten......😥)
- For each pair of message, look into the similar property and put them into the same set by hooking on one of them as parent. Finally count the number of sets
```cpp=
for(int i = 0; i < n; i++)
{
    for(int j = i + 1; j < n; j++)
    {
        if(areSimiliar(arr[i],arr[j])) Union(i, j);
    }
}
```
- When comparing similarity, only the difference by two can be accepted
```cpp=
bool areSimiliar(string &str1, string &str2)
{
    if(str1 == str2) return true;
    int count = 0;
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] != str2[i]) count++;
    }
    if(count == 2) return true;
    return false;  
}
```
- When doing `Union`, find the parent of each of them, and replace one of the parent as the other to hook on the new parent
```cpp=
void Union(int a, int b)
{
    int p = find(a);
    int q = find(b);
    if(p == q) return;
    par[p] = q;        
}
```
- To find a parent, find the one with value as root to show the root parent source
```cpp=
int find(int a)
{
    if(par[a] < 0) return a;
    return par[a] = find(par[a]);
}
```