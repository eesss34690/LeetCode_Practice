# 649. Dota2 Senate
###### tags: `leetcode`
## Description
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

- **Ban one senator's right**: A senator can make another senator lose all his rights in this and all the following rounds.
- **Announce the victory**: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.

Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

- Example 1:

>Input: senate = "RD"
Output: "Radiant"
>>Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.

- Example 2:

>Input: senate = "RDD"
Output: "Dire"
>>Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.

- Constraints:

>n == senate.length
1 <= n <= 104
senate[i] is either 'R' or 'D'.

## Solution
- The problem can be classified into queue structure
- For each of the policy, put them into different queue
```cpp=
queue<int> q1, q2;
int n = senate.length();
for (int i = 0; i < n; i++)
{
    if (senate[i] == 'R') q1.push(i);
    else q2.push(i);
}
```
- For each of the parties in the queue, pop the front one and see who can win the race (who appears first). The winner can be placed into the contest list again with the new index that should not overlap with the others
```cpp=
while (!q1.empty() && !q2.empty()) {
    int r_index = q1.front(), d_index = q2.front();
    q1.pop(), q2.pop();
    if (r_index < d_index) q1.push(r_index + n);
    else q2.push(d_index + n);
}
```
- After one of the queue becomes empty, the answ is the last one exists