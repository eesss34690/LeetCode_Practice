# 38_Count_and_Say
###### tags: `leetcode` `38`
## Problem Statement
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

> countAndSay(1) = "1"
> countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.

To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

- For example, the saying and conversion for digit string "3322251":

> Given a positive integer n, return the nth term of the count-and-say sequence.

- Example 1:

> Input: n = 1
> Output: "1"
> Explanation: This is the base case.
- Example 2:

> Input: n = 4
> Output: "1211"
> Explanation:
>> countAndSay(1) = "1"
>> countAndSay(2) = say "1" = one 1 = "11"
>> countAndSay(3) = say "11" = two 1's = "21"
>> countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 
- Constraints:

> 1 <= n <= 30

## Solution
- To do this recursive function, add another function ```convert``` to change the string value.
- Inside the code, when confronted with 1 character, see whether it is the sam one from the last character.
    - If the same, kep counting.
    - Otherwise, add the last element into the string answer and its # of appearance.
```cpp=
string convert(string ans)
{
    string a;
    int ind= 0;
    for (int i= 1; i< ans.length(); i++)
    {
        if (ans[i]!= ans[ind])
        {
            a+= to_string(i- ind)+ ans[ind];
            ind= i;
        }
    }
    a+= to_string(ans.size()- ind)+ ans[ind];
    return a;
}
```
- When calling this function, remember to substract the ```n``` to satisfy the condition.

```cpp=
string ans= "11";
while (--n!= 1)
{
    ans= convert(ans);
}
return ans;
```