# 30_Substring_with_Concatenation_of_All_Words
###### tags: `leetcode` `30`
## Problem Statement
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

- Example 1:

> Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
- Example 2:

> Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
- Example 3:

> Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
 
- Constraints:

> 1 <= s.length <= 104
s consists of lower-case English letters.
1 <= words.length <= 5000
1 <= words[i].length <= 30
words[i] consists of lower-case English letters.
## Solution
- Because every element **has the same length**, it is much easier to solve.
- Use ```map``` to remember the corresponding count of the test ```s```.

```cpp=
unordered_map<string,int> og_count;
for(auto i:words){
    og_count[i]++;
}
```
- The number to check is bound to be ```num of words* word length```, therefore, check the window.
```cpp=
string check=s.substr(i,num_words*len);
```
- Use check map to record whether it is like our standard ```og_count```.
- If the word is lost or the count has exceed the requirement-> fail.

```cpp=
for(;j<check.length();j+=len){
    string temp=check.substr(j,len);
    if(og_count.find(temp)==og_count.end()) break;
    if(count[temp]==og_count[temp]) break;
    count[temp]++;
}
```
- If the ```break``` is not invoked, add the position into answer.

```cpp=
if(j==check.length()) answer.push_back(i);
```