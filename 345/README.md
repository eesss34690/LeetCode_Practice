# 345_Reverse_Vowels_of_a_String 
###### tags: `leetcode` `345`
## Problem Statement
Write a function that takes a string as input and reverse only the vowels of a string.

- Example 1:

> Input: "hello"
> Output: "holle"
- Example 2:

> Input: "leetcode"
> Output: "leotcede"

## Solution
- Store the index of the vowels and the vowels itself.
```cpp=
for (int i= s.length()- 1; i> -1; i--)
{
    if (s[i]== 'a'|| s[i]== 'A'|| s[i]== 'e'|| s[i]== 'E'|| s[i]== 'i'|| s[i]== 'I'|| s[i]== 'o'|| s[i]== 'O'|| s[i]== 'u'|| s[i]== 'U')
    {
        vow.push_back(s[i]);
        ind.push_back(i);
        s[i]= '0';
    }            
}
```
- Scan through each element to modify the vowels in reverse order.
```cpp=
for (int i= 0; i< ind.size(); i++)
{
    s[ind[ind.size()- i- 1]]= vow[i];
}
```