# 151_Reverse_Words_in_a_String
###### tags: `leetcode` `151`
## Problem Statement
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

- Example 1:

> Input: s = "the sky is blue"
> Output: "blue is sky the"
- Example 2:

> Input: s = "  hello world  "
> Output: "world hello"
> Explanation: Your reversed string should not contain leading or trailing spaces.
- Example 3:

> Input: s = "a good   example"
> Output: "example good a"
> Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
- Example 4:

> Input: s = "  Bob    Loves  Alice   "
> Output: "Alice Loves Bob"
- Example 5:

> Input: s = "Alice does not even like bob"
> Output: "bob like even not does Alice"
 
- Constraints:

> 1 <= s.length <= 10^4^
> s contains English letters (upper-case and lower-case), digits, and spaces ' '.
> There is at least one word in s.

## Solution
- Since they are reversing only the word, not the entire string, need to remember the starting point and the end point of the index.
```cpp=
if (s[i]!= ' '&& o) // the end point
{
    j= i; //end point
    if (!ans.empty())
        ans.append(" "); //if not the first element, add space
    o= 0; //the variable to control remembering the start or the end
}
```
```cpp=
else if (s[i]== ' '&& !o) // the starting point
{
    o= 1;
    ans.append(s.begin()+ i+ 1, s.begin()+ j+ 1); // add into the final array
}
```
```cpp=
if (s[0]!= ' '&& !o) // the first element is not included, add outside the loop
{
    ans.append(s.begin(), s.begin()+ j+ 1);
}
```