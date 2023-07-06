# 1297. Maximum Number of Occurrences of a Substring
###### tags: `leetcode`
## Description
Given a string s, return the maximum number of ocurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.

- Example 1:

>Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
>>Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

- Example 2:

>Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
>>Explanation: Substring "aaa" occur 2 times in the string. It can overlap.

- Constraints:

>1 $\leq$ s.length $\leq 10^5$
1 $\leq$ maxLetters $\leq$ 26
1 $\leq$ minSize $\leq$ maxSize $\leq$ min(26, s.length)
s consists of only lowercase English letters.

## Solution
- It is a simple brute force with a little strategy in order to speed up
- Even though there is options for `maxSize`, there is no need to consider it because the more letters present, the less likely the number of occurence would rise. Also, there is regulation for `maxLetters`. If the condition meets for `maxLetters` with size more than `minSize`, the substring `minSize` must meet the regulation!
- As the result, count for current `minSize` combination. Add them into the map for counting
```cpp=
unordered_map<int,int> count; \\ for current minSize substring
unordered_map<string,int> occurence; \\ for all qualified substring counting
```
- With each combination, erase the former first one and append the current last one into map
```cpp=
for(int i = 0; i < s.length(); i++)
{
    count[s[i]]++;
    if(i - start + 1 > minSize)
    {
        if(--count[s[start]] == 0)
            count.erase(s[start]);
        start++;
    }
}
```
- For qualification searching, seek the minimum size and the maxLetters check for map size. Update the maximum for the occurence of the substring
```cpp=
if(i - start + 1 == minSize && count.size() <= maxLetters)
    result = max(result, ++occurence[s.substr(start, i - start + 1)]);
```
