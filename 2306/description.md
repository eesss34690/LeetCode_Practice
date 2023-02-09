# 2306. Naming a Company
###### tags: `leetcode`
## Description
You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.

- Example 1:

>Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
>>Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.

- Example 2:

>Input: ideas = ["lack","back"]
Output: 0
>>Explanation: There are no valid selections. Therefore, 0 is returned.

- Constraints:

>2 <= ideas.length <= 5 * 104
1 <= ideas[i].length <= 10
ideas[i] consists of lowercase English letters.
All the strings in ideas are unique.

## Solution
- The problem can be simplified by looking into various set from different characters
- The leading character possess a set of following string, which should not be duplicated
```cpp=
unordered_set<string> count[26];
for (auto& s: ideas)
    count[s[0] - 'a'].insert(s.substr(1));
```
- For pairing of all the combination of the 2 letters, check the valid different string for the two and then add then into the result
```cpp=
for(int i = 0; i < 26; ++i)
    for(int j = i + 1; j < 26; ++j) {
        long long c1 = 0L, c2 = 0L;
        for (auto& c: count[i])
            if (!count[j].count(c)) c1++;
        for (auto& c: count[j])
            if (!count[i].count(c)) c2++;
        res += c1 * c2;
    }
```
- Because we can flip the result, the answer should multiplied by 2
```cpp=
return res * 2;
```
