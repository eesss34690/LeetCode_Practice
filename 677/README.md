# 677_Map_Sum_Pairs
###### tags: `leetcode` `677`
## Problem Statement
Implement the ```MapSum``` class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.
- Example 1:

> Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]
> > Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 
- Constraints:

> $1 \leq key.length,\ prefix.length \leq 50$
key and prefix consist of only lowercase English letters.
$1 \leq val \leq 1000$
At most 50 calls will be made to insert and sum
## Solution
- The problem can be implemented by using ```unordered_map```.
```cpp=
unordered_map<string, int> pairs;
```
- By constructing the key and value pairs, using operand ```[]``` can be illustrated as insert or replace the value with the same key
```cpp=
pairs[key]= val;
```
- The sum can be described as looking for every keys in the map and see the partial string whether it fits.
```cpp=
int len= prefix.length(), ans= 0;
for (auto i= pairs.begin(); i!= pairs.end(); i++)
{
    if (len<= (i->first).length()&& (i->first).substr(0,len)== prefix)
    {
        ans+= i->second;
    }
}
```