# 299_Bull_and_Cows
###### tags: `leetcode` `299`
## Problem Statement
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

 

- Example 1:

> Input: secret = "1807", guess = "7810"
> Output: "1A3B"
> Explanation: Bulls are connected with a '|' and cows are underlined:
> "1807"
    |
> "7810"
- Example 2:

> Input: secret = "1123", guess = "0111"
> Output: "1A1B"
> Explanation: Bulls are connected with a '|' and cows are underlined:
> "1123"        "1123"
>   |      or     |
> "0111"        "0111"
> Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.
- Example 3:

> Input: secret = "1", guess = "0"
> Output: "0A0B"
> Example 4:
> 
> Input: secret = "1", guess = "1"
> Output: "1A0B"
 

- Constraints:

> 1 <= secret.length, guess.length <= 1000
> secret.length == guess.length
> secret and guess consist of digits only.

## Solution
- To get the correct result, need to split the 2 calculation. ```A``` needs to be determined first since it has priority. then ```B``` is considered.
- Calculate how many ```A``` and then put the rest into the frequency of vector
```cpp=
vector<int> s(10, 0), g(10, 0); //vector pre-construction
int a= 0, b= 0; // a, b count
for (int i= 0; i< secret.length(); i++)
{
    if (secret[i]== guess[i])
    {
        a++;
    }
    else
    {
        s[secret[i]- '0']++; // the num of that number
        g[guess[i]- '0']++;
    } 
}
```
- ```B```is determined from the smallest count of each number
```cpp=
for (int i= 0; i< 10; i++)
{
    b+= min(s[i], g[i]);
}
```
- Return the string with concatenation
```cpp=
return to_string(a)+ 'A'+ to_string(b)+ 'B';
```