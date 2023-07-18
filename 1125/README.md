# 1125. Smallest Sufficient Team
###### tags: `leetcode`
## Description
In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

It is guaranteed an answer exists.

- Example 1:

>Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]

- Example 2:

>Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]

- Constraints:

>1 <= req_skills.length <= 16
1 <= req_skills[i].length <= 16
req_skills[i] consists of lowercase English letters.
All the strings of req_skills are unique.
1 <= people.length <= 60
0 <= people[i].length <= 16
1 <= people[i][j].length <= 16
people[i][j] consists of lowercase English letters.
All the strings of people[i] are unique.
Every skill in people[i] is a skill in req_skills.
It is guaranteed a sufficient team exists.

## Solution
- The problem is related to `dynamic programming`, but we can leverage on `bitmask` to help the set selection
- For each of the skills, we use bit 1 as selected and 0 otherwise. As the result, use a `unordered_map` to store the corresponding set of bit value and the minimum people set needed in the set
```cpp=
unordered_map<int, vector<int>> dp;
dp.reserve(1 << req_skills.size());
dp[0] = {};
```
- In order to classify the people, use another map to map the string to the index
```cpp=
unordered_map<string, int> skillmap;
for (int i = 0; i < req_skills.size(); i++) skillmap[req_skills[i]] = i;
```
- For each of the people, calculate their own set value and check for each of the set whether the newly added person can make the size of the requested set containing smaller number of people
```cpp=
cur = 0;
for (auto &j : people[i]) cur |= 1 << skillmap[j];
for (auto it = dp.begin(); it != dp.end(); it++)
{
    comb = it->first | cur;
    if (dp.find(comb) == dp.end() || dp[comb].size() > 1 + dp[it->first].size())
    {
        dp[comb] = it->second;
        dp[comb].push_back(i);
    }
}
```
- Return the final set of people
```cpp=
return dp[(1 << req_skills.size()) - 1];
```