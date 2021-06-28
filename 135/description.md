# 135_Candy
###### tags: `leetcode` `135`
## Problem Statement
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

- Example 1:

> Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
- Example 2:

> Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

- Constraints:

> n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104

## Solution
- To do this, the connection is between the closed 2.
- There are some variables to remember
    - m: the position of the biggest (the place where change may needed.)
    - temp: the last value of the answer
    - ma: acesending maximum value 
- In the connected 2 elements, the only careabout is ```not equal```.
    - If it is acesending, add the temp and add the answer, update m and ma.

```cpp=
if (ratings[i]> ratings[i- 1])
{
    temp++;
    ans += temp;
    m= i;
    ma= temp;
}
```
- If it is equal, the next one can be minimum.

```cpp=
else
{
    temp= 0;
    m= i;
}
```
- If it is descending, there are 2 cases
    - the last one is 0: add from m to now by 1 and check whether the last one of m is the equal one to m, add 1 if needed.
    - If no, the descending just need to be 0

```cpp=
if (ratings[i]< ratings[i- 1])
{
    if (temp== 0) 
    {
        ans+= i- m;
        if (ma<= i- m&& ratings[m]!= ratings[m- 1])
            ans++;
    }
    else
    {
        temp= 0;
        m= i;
    }
}
```