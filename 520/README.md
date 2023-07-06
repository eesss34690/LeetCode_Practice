# 520. Detect Capital
###### tags: `leetcode`
## Problem Statement
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

- Example 1:

>Input: word = "USA"
Output: true

- Example 2:

>Input: word = "FlaG"
Output: false

- Constraints:

>1 <= word.length <= 100
word consists of lowercase and uppercase English letters.

## Solution
- This is a simple distinguish task
- By categorizing the sequences for the types, upper case till the end, upper case only the first one, all lower cases, check whether the case is true till the last one.
```cpp=
if (word[0] - 'a' >= 0 && word[0] - 'a' < 27)
{
    for (int i = 1; i < word.length(); i++)
    {
        if (word[i] - 'a' < 0 || word[i] - 'a' > 26)
            return false;
    }
}
```

```cpp=
if (word[1] - 'a' >= 0 && word[1] - 'a' < 27)
{
    for (int i = 2; i < word.length(); i++)
    {
        if (word[i] - 'a' < 0 || word[i] - 'a' > 26)
            return false;
    }
} else {
    for (int i = 2; i < word.length(); i++)
    {
        if (word[i] - 'A' < 0 || word[i] - 'A' > 26)
            return false;
    }
}
```