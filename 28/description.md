# 28_Implement_strStr()
###### tags: `leetcode` `28`
## Problem Statement

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

- Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

- Example 1:

> Input: haystack = "hello", needle = "ll"
> Output: 2
- Example 2:

> Input: haystack = "aaaaa", needle = "bba"
> Output: -1
- Example 3:

> Input: haystack = "", needle = ""
> Output: 0

- Constraints:

> 0 <= haystack.length, needle.length <= 5 * 10^4^
haystack and needle consist of only lower-case English characters.
## Solution
- Use dummy solution, simply look for the same element and proceed.
- If fail to match, turn back to the original spot and resume.
```cpp=
int j = 0;
for(int i = 0 ; i < haystack_len ; i++){

    if(haystack[i] == needle[j]){
		j++;
	}else{
		i = i-j;
		j = 0;
	}
	if(j==needle_len){
		return i - j +1 ;
	}
}
```