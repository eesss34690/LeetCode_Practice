# 953. Verifying an Alien Dictionary
###### tags: `leetcode`
## Description
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

- Example 1:

>Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
>>Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

- Example 2:

>Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
>>Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

- Example 3:

>Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
>>Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

- Constraints:

>1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.

## Solution
- The problem only relies on relative strings, therefore, use the 2 siblings to compare
- When comparing, find the sequence in the order string to see if it violate the ordr, if it is met, just break out and compare the next pair, if it violate the sequence, just return false.
- If the result is the same, compare the next character
```cpp=
while (idx < words[i].length() && idx < words[i + 1].length())
{
    ans = order.find(words[i][idx]) - order.find(words[i + 1][idx]);
    if (ans > 0)
        return false;
    if (ans < 0)
        break;
    idx++;
}
```
- Check that whether it is the boundary that makes it jump out of the loop. If positive and it is the second one that is shorter, return false
```cpp=
if (idx == words[i + 1].length() && idx != words[i].length())
    return false;
```
