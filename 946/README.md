# 946. Validate Stack Sequences
###### tags: `leetcode`
## Description
Given two integer arrays `pushed` and `popped` each with distinct values, return `true` *if this could have been the result of a sequence of push and pop operations on an initially empty stack, or `false` otherwise*.

- Example 1:

>Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
>>Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

- Example 2:

>Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
>>Explanation: 1 cannot be popped before 2.

- Constraints:

>$1 \leq pushed.length \leq 1000$
$0 \leq pushed[i] \leq 1000$
All the elements of pushed are unique.
popped.length == pushed.length
popped is a permutation of pushed.

## Solution
- The problem can be solved by literally establish a stack and try to push or pop the stuff
- Construct a stack and push according to the pushed array. Pop the top of it if it is the current stamp of popped array
```cpp=
for (auto &i : pushed) {
    st.push(i);
    while (st.size() > 0 && st.top() == popped[j])
    {
        st.pop();
        j++;
    }
}
```
- Return the stack size because the identical stack would result in the empty result
```cpp=
return st.size() == 0;
```
