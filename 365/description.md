# 365_Water_and_Jug_Problem
###### tags: `leetcode` `1561`
## Problem Statement
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

- Operations allowed:

> Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
- Example 1: (From the famous "Die Hard" example)

> Input: x = 3, y = 5, z = 4
Output: True
- Example 2:

> Input: x = 2, y = 6, z = 5
Output: False
 
- Constraints:

> 0 <= x <= 10^6^
0 <= y <= 10^6^
0 <= z <= 10^6^

## Solution
- This problem can be deciphered as below:
    $z = m\times x+n\times y \ \  {m,n \in \mathbb{Z}}$
- The final result is the composition of some partition ratio of the 2 jugs.
- To see wether it is able to be solved, the $\mathbb{Bézout's \ \ identity}$ claims that the ```z``` there is bound to be the multiple of ```greatest common divisor```. As the result, the problem can be simplied as below.

```cpp=
bool canMeasureWater(int x, int y, int z) {
    // if the total water amount is bigger than the sum of the 2 jugs, it is impossible.
    if (x+ y< z) return false;
    // If the required water is 0, it is bound to be satisfied.
    if (!z) return true;
    // If the required amount is the multiple of the gcd of the 2 jugs, possible.
    if (z% __gcd(x, y)) return false;
        return true;
}
```