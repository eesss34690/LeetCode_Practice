# 1639. Number of Ways to Form a Target String Given a Dictionary
###### tags: `leetcode`
## Description
You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
Repeat the process until you form the string target.
Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

- Example 1:

>Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
>>Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

- Example 2:

>Input: words = ["abba","baab"], target = "bab"
Output: 4
>>Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")

- Constraints:

>$1 \leq words.length \leq 1000$
$1 \leq words[i].length \leq 1000$
All strings in words have the same length.
$1 \leq target.length \leq 1000$
words[i] and target contain only lowercase English letters.

## Solution
- The problem can be solved by dynamic programming
- To construct a dynamic programming array, the value of the index is the sub-array that can be satisfied in the conditional targeted string
- The zero substring is declared as 1
```cpp=
int n = words[0].size();
int m = target.size();
vector<int> dp(m + 1, 0);
dp[0] = 1;
```
- To construct the possibility set, we can calculate the number of occurance in the index
```cpp=
vector<vector<int>> count(n, vector<int>(26, 0));
for (const string& word : words) {
    for (int i = 0; i < n; i++) {
        count[i][word[i] - 'a']++;
    }
}
```
- For each of the possibilities, the combination is the product of the different indexes. As the result, product them together to get the result
```cpp=
for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
        dp[j+1] += (int)((long)dp[j] * count[i][target[j] - 'a'] % 1000000007);
        dp[j+1] %= 1000000007;
    }
}
```