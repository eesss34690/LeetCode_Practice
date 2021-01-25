# 383_Ransom_Note
###### tags: `leetcode` `383`
## Problem Statement
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

- Example 1:

> Input: ransomNote = "a", magazine = "b"
> Output: false
- Example 2:

> Input: ransomNote = "aa", magazine = "ab"
> Output: false
- Example 3:

> Input: ransomNote = "aa", magazine = "aab"
> Output: true
 
- Constraints:

> You may assume that both strings contain only lowercase letters.

## Solution
- Because the sequence can be adjusted, we need to find each elements and then delete it in case reuse it.
```cpp=
for (int i= 0; i< ransomNote.length(); i++)
{
    size_t found= magazine.find(ransomNote[i]);
    if (found== -1)
        return false;
    magazine.erase(found, 1);
}
return true;
```