# 229_Majority_Element_II
###### tags: `leetcode` `229`
## Problem Statement
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

- Follow-up: Could you solve the problem in linear time and in O(1) space?
- Example 1:

> Input: nums = [3,2,3]
> Output: [3]
- Example 2:

> Input: nums = [1]
> Output: [1]
- Example 3:

> Input: nums = [1,2]
> Output: [1,2]

- Constraints:

> 1 <= nums.length <= 5 * 10^4^
> -10^9^ <= nums[i] <= 10^9^

## Solution
- In this problem, there s one algorithm that can solve it in O(n) time - **Boyer Moore Algorithm**

---

### Boyer Moore Algorithm
:::spoiler
- A method for **preprocessing** the string of data to make count
- Two elements included
    - Pattern: the key we want to search
    - Text: the original line to be examined
- Move the upmost by two methods
    - good-suffix shift: the two characters match
    - bad-character shift: the two charcter does not match
- Start searching with the **last** element, if not match, need to shift for a certain number of bit.
![](https://i.imgur.com/nm16Qdq.png)
*fig. 1 ```S``` and ```E``` does not match, bad character*
- Look at the former from the pattern, if there is no one like ```the last element checked of the text```, shift the upmost.
*Like the description above, no one matches ```S```*
- Otherwise, shift to the position where the last element checked of the text matches the pattern index.
![](https://i.imgur.com/8lHS29f.png)
*fig. 2 ```P```from ```SIMPLE``` is examined, and found it matches with ```P``` from ```EXAMPLE```*
![](https://i.imgur.com/L9vVhqT.png)
*fig. 3 Shift it to match the 2 ```P```*
:::
---

- Back to the problem, how to use the method for this problem?
    - The main idea is that there are at most **```2``` index** to be counted. Therefore,use BM algo. can do a linear search and see the possible frequent apeearing elements.
    - For example, ```[2,1,1,3,1,4,5,6]```
    - We use 2 spaces for storing the possible candidates ```may1```, ```may2```, with 2 corresponding counting ```count1```, ```count2```.
    - Add the count if match the text, if not matched, substract both the count by 1.
    - If the count is ```0```, means that it is unlikely the candidates of the frequent text, replace it with the current text.
```cpp=
int count1= 0;
int count2= 0;
int may1, may2;           
for (int i= 0; i< nums.size(); i++)
{
    if (nums[i]== may1) //match the 1st one
    {
        count1++;
    }
    else if (nums[i]== may2) //match the 2nd one
    {
        count2++;
    }
    else if (count1== 0) //1 is to be replaced
    {
        may1= nums[i];
        count1++;
    }
    else if (count2== 0) //2 is to be replaced
    {
        may2= nums[i];
        count2++;
    }
    else //non of the problem occur but no one match
    {
        count1--;
        count2--;
    }
}
```
- After the algo., there are 2 candidates, but the count is not the actual number of frequency. Therefore, re-compute them.
```cpp=
count1 = 0;
count2 = 0;
for (int i= 0; i< nums.size(); i++)
{
    if (may1== nums[i]) count1++;
    else if (may2== nums[i]) count2++;
}
```
- After that, tell the frequency whether they fit the boundary.
```cpp=
vector<int> ans;
if (count1> nums.size()/ 3)
{
    ans.push_back(may1);
}
if (count2> nums.size()/ 3)
{
    ans.push_back(may2);
}
return ans;
```