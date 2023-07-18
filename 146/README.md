# 146. LRU Cache
###### tags: `leetcode`
## Description
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

- Example 1:

>Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
>>Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

- Constraints:

>1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

## Solution
- To solve the issue, we can use a map to store the key and the value
- We need to know the calling count as well because we ned to evict the least used one. Use a counter to check how many times it is iterated and the sequence of calling with queue
```cpp=
unordered_map<int, vector<int>> mp;
queue<int> q;
```
- With the construction, set the capacity constraint
```cpp=
cap = capacity;
```
- Find the mapping of the key and add the count if it presents. Also push it into the queue for the calling sequence record
```cpp=
if (mp.find(key) != mp.end())
{
    mp[key][1]++;
    q.push(key);
    return mp[key][0];
}
return -1;
```
- When putting the value, check the existence first and then update the value and counter and push to queue if it presents
```cpp=
if (mp.find(key) != mp.end())
{
    mp[key][0] = value;
    mp[key][1]++;
    q.push(key);
}
```
- If it doese not present, add one value into the map and push to queue
```cpp=
else
{
    mp[key] = {value, 1};
    q.push(key);
}
```
- After adding, check whether the capacity has already exceeded. Iterate through queue and decrease the counter for the current value until it is the last one being called. Evict the one with 0 count and it is over
```cpp=
if (mp.size() > cap)
{
    while (1)
    {
        int cur = q.front();
        q.pop();
        mp[cur][1]--;
        if (mp[cur][1] == 0)
        {
            mp.erase(cur);
            break;
        }
    }
}
```