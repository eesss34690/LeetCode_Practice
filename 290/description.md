# 290_Word_Pattern
###### tags: `leetcode` `290`
## Problem Statement
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

- Example 1:

> Input: pattern = "abba", s = "dog cat cat dog"
> Output: true
- Example 2:

> Input: pattern = "abba", s = "dog cat cat fish"
> Output: false
- Example 3:

> Input: pattern = "aaaa", s = "dog cat cat dog"
> Output: false
- Example 4:

> Input: pattern = "abba", s = "dog dog dog dog"
> Output: false
 
- Constraints:

> 1 <= pattern.length <= 300
>> pattern contains only lower-case English letters.

> 1 <= s.length <= 3000
>> s contains only lower-case English letters and spaces ' '.

> s does not contain any leading or trailing spaces.
> All the words in s are separated by a single space.

## Solution
- To tackle with this problem, the string needs preprocessing.
- Because it contains only 1 space, use ```find``` to see how to split the words and then push the single word into the vector.
- If the last word does not follow with a space, it would be ignored. Add in the final line to add the word.

```cpp=
while(string::npos != pos)
{
    pat.push_back(s.substr(ori, pos- ori));
    ori = pos+ 1;
    pos = s.find(" ", ori);
}
if (ori != s.length())
    pat.push_back(s.substr(ori));
```

- See whether the ```pattern``` and ```string``` have the same length. Return false if otherwise.

```cpp=
if (pattern.length()!= pat.size())
    return false;
```

- After, just use the solution like ```205```, map is introduced and see whether they are ```1 to 1``` match.

```cpp=
table[pattern[0]]= pat[0];
for (int i= 1; i< pattern.length(); i++)
{
    iter= table.find(pattern[i]);
    // Not matching the original mapping
    if (iter!= table.end()&& iter->second != pat[i])
    {
        return false;
    }
    if (iter== table.end())
    {
        // n to 1 if this is positive
        if (find(pat.begin(), pat.begin()+ i, pat[i])!= pat.begin()+ i) 
        {
            return false;
        }
        // add the pattern into map
        table[pattern[i]]= pat[i];
    }
}
```