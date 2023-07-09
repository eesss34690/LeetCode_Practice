# 2272. Substring With Largest Variance
###### tags: `leetcode`
## Description
The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

A substring is a contiguous sequence of characters within a string.

- Example 1:

>Input: s = "aababbb"
Output: 3
>>Explanation:
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.

- Example 2:

>Input: s = "abcde"
Output: 0
>>Explanation:
No letter occurs more than once in s, so the variance of every substring is 0.

- Constraints:

>1 <= s.length <= 104
s consists of lowercase English letters.

## Solution
- The problem can be seem as the `Kadane Algorithm`
- Because we care about the value for the maximum and minimum difference of occurrence, we only need to take care of two characters at one time
- Collect all the characters appear in the string and then do the iteration
```cpp=
unordered_set<char> sets(begin(s), end(s));
for (auto &a : sets)
{
    for (auto &b : sets)
```
- For the combination, we force the character `a` appears more than character `b` because we must iterate through both `a>b` and `b>a`. Also, we need to check whether `b` already appears and setup the initial `b` for checkup
- For `a`, the value is `+1` and `b` is `-1`. Everytime when the string appears, get the value for `a` first. If it is `b`, set `haveB` to true and check whether `b` has already exceeded the occurence of `a`. In that case, we only allow one more appearance of `b` in order to avoid the final result to be `b>a`. Once the value of `a` exceeds `b`, we set `firstB` as false to let it restart again
```cpp=
for (char &c : s)
{
    val += c == a;
    if (c == b)
    {
        haveB = 1;
        if (firstB && val >= 0) firstB = 0;
        else if (--val < 0)
        {
            firstB = 1;
            val = -1;
        }
    }
    ans = max(ans, haveB ? val : 0);
}
```