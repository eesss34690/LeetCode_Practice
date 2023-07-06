# 1146. Snapshot Array
###### tags: `leetcode`
## Description
Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

- Example 1:

>Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
>>Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5

- Constraints:

>1 <= length <= 5 * 104
0 <= index < length
0 <= val <= 109
0 <= snap_id < (the total number of times we call snap())
At most 5 * 104 calls will be made to set, snap, and get.

## Solution
- The problem can be regarded as the update for version in each index
- To keep it simple, let the vector index be the true index of the array. The value and version is the value inside each vector
```cpp=
vector<vector<pair<int, int>>> shot;
int id;
```
- To begin with, when setting the new value, we need to make sure that the array has no value for current version. Because we can not update the older version value after snapshot, it is obvious that the one closest to the current version is the last updated one
- Check the existence of index value before accessing the last element in order to avoid Overflow
```cpp=
if (!shot[index].empty() && shot[index].back().first == id) shot[index].back().second = val;
else shot[index].push_back(make_pair(id, val));
```
- When doing snapshot, just update the version number
```cpp=
return id++;
```
- When accessing the element, find the upper bound of the pair. The value for the searching should be set to `INT_MAX` because we would like the element that has **strictly greater version** than the one requested
```cpp=
auto temp = upper_bound(shot[index].begin(), shot[index].end(), make_pair(snap_id, INT_MAX));
```
- If there is no version that is greater than the version, it is the original value - `0`.
```cpp=
if (temp == shot[index].begin()) return 0;
```
- Return the value that is the previous one of the searching result
```cpp=
return (temp - 1)->second;
```