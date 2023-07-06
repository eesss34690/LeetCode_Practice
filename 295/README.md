# 295_Find_Median_from_Data_Stream
###### tags: `leetcode` `295`
## Problem Statement
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:
```!
MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
```

- Example 1:

> Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

> Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 
- Constraints:

> -105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.

- Follow up:

> If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

## Solution
- This problem can be solved by using ```Heapmap```
- To construct a heap, we can use ```priority_queue``` as a abstract symbol of heap.
```cpp=!
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
```
- To begin with , we need to halve the data, which means that one is ```minheap``` with the data of bigger values and ```maxheap``` with the data of smaller values.
- Once a data is inserted to the maxheap, add the top of maxheap to the minheap.

```cpp=
maxHeap.push(num);
minHeap.push(maxHeap.top());
        maxHeap.pop();
```
- We made constraits for the minheap to have size greater than the maxheap. If not true, pop the data again.

```cpp=!
if (minHeap.size() > maxHeap.size()) {
    maxHeap.push(minHeap.top());
    minHeap.pop();
}
```

- To find the median, it is either the top of maxheap or the average of both the top according to the size.

```cpp=!
if (maxHeap.size() > minHeap.size()) 
    return maxHeap.top();
return (maxHeap.top() + minHeap.top()) / 2.0;
```