# 705. Design HashSet
###### tags: `leetcode`
## Description
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

- Example 1:

>Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]
>>Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)

- Constraints:

>0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.

## Solution
- To construct the hashset, simply use the set stl to construct the built-in structure
```cpp=
unordered_set<int> table;
```
- For adding the key, use the `insert` function to finish the task
```cpp=
void add(int key) {
    table.insert(key);
}
```
- For removing the element, find the existence of the key and remove if it is shown
```cpp=
void remove(int key) {
    auto temp = find(table.begin(), table.end(), key);
    if ( temp != table.end()) table.erase(temp);
}
```
- To check the existence, use the contains with find built-in function
```cpp=
bool contains(int key) {
    return find(table.begin(), table.end(), key) != table.end();
}
```
