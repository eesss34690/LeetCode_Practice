# 2438. Range Product Queries of Powers
###### tags: `leetcode`
## Problem Statement
Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.

You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.

Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

- Example 1:

>Input: n = 15, queries = [[0,1],[2,2],[0,3]]
Output: [2,4,64]
>>Explanation:
For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
Answer to 2nd query: powers[2] = 4.
Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is returned.

- Example 2:

>Input: n = 2, queries = [[0,0]]
Output: [2]
>>Explanation:
For n = 2, powers = [2].
The answer to the only query is powers[0] = 2. The answer modulo 109 + 7 is the same, so [2] is returned.

- Constraints:

>1 <= n <= 109
1 <= queries.length <= 105
0 <= starti <= endi < powers.length

## Solution
- The adding to `n` is equalivent to getting the binary representation of the number
```cpp=
void convertToBin(int n, vector<int>& binary, int times) {
    if (n % 2 == 1)
        binary.push_back(pow(2, times));
    if (n > 1)
        convertToBin(n / 2, binary, times + 1);
}
```
- As for the query part, simply use brute force to generate the for loop for the answer
```cpp=
for (int i = 0; i < queries.size(); i++)
{
    temp = 1;
    for (int j = queries[i][0]; j <= queries[i][1]; j++)
        temp = (temp * (binary[j] % 1000000007)) % 1000000007;
    ans[i] = temp;
}
```