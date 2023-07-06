# 443. String Compression
###### tags: `leetcode`
## Description
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

- Example 1:

>Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
>>Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

- Example 2:

>Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
>>Explanation: The only group is "a", which remains uncompressed since it's a single character.

- Example 3:

>Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
>>Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

- Constraints:

>$1 \leq chars.length \leq 2000$
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

## Solution
- The problem does not contain specific algorithm for achieving the task, simply do it straight forward can solve it
- Build a new character vector and start to count by comparing with the first index of the current character until the end or the new character appears
```cpp=
compression.push_back(chars[idx]);
while (idx < chars.size())
{
    if (chars[first] == chars[idx])
        idx++;
    else
        break;
}
```
- For the character emplacement, just transform the counting to the amount of the current character into string and append them one by one.
```cpp=
temp = idx - first;
if (temp > 1)
{
    auto val = to_string(temp);
    for (auto &i : val)
        compression.push_back(i);
}
```
- Break the loop by checking the boundary and put the first index of the next one to the current last index
```cpp=
if (idx == chars.size())
    break;
first = idx;
```
