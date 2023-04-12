# 71. Simplify Path
###### tags: `leetcode`
## Description
Given a string `path`, which is an **absolute path** (starting with a slash `'/'`) to a file or directory in a Unix-style file system, convert it to the simplified **canonical path**.

In a Unix-style file system, a period `'.'` refers to the current directory, a double period `'..'` refers to the directory up a level, and any multiple consecutive slashes (i.e. `'//'`) are treated as a single slash `'/'`. For this problem, any other format of periods such as `'...'` are treated as file/directory names.

The **canonical path** should have the following format:

- The path starts with a single slash `'/'`.
- Any two directories are separated by a single slash `'/'`.
- The path does not end with a trailing `'/'`.
- The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period `'.'` or double period `'..'`)

Return the *simplified* **canonical path**.

- Example 1:

>Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

- Example 2:

>Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

- Example 3:

>Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

- Constraints:

>$1 \leq path.length \leq 3000$
`path` consists of English letters, digits, period `'.'`, slash `'/'` or `'_'`.
`path` is a valid absolute Unix path.

## Solution
- The problem can be solved by using stack to store the directory in order.
- The first task to deal with is the slash occuring for several times, which should be ignored. As the result, we iterate nd check the slash before operation
```cpp=
for (int i = 0; i < path.size(); ++i)
    {
        if (path[i] != '/')
        {
            // ...
```
- Accumulate the string until the first slash meets, which means the substring is generated
```cpp=
temp = "";
while (i < path.size() && path[i] != '/') temp += path[i++];
```
- The substring may be the last page indicator `..`, non-op operator `.`, or normal directory
- The empty stack means last page indicator is a non-op operation
```cpp=
if (temp == "..")
{
    if(!st.empty()) st.pop();
}
else if (temp != ".") st.push(temp);
```
- If the final result has nothing in the stack, it means that the path is the root path. Else we concanate the path by popping up one by one and add it to the front
```cpp=
if (st.empty()) return "/";
while (!st.empty())
{
    res = "/" + st.top() + res;
    st.pop();
}
return res;
```