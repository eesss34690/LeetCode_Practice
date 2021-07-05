# 68_Text_Justification
###### tags: `leetcode` `68`
## Problem Statement
Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

- Note:

> A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.

- Example 1:

> Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
- Example 2:

> Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified becase it contains only one word.
- Example 3:

> Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 
- Constraints:

> 1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth

## Solution
- For each one ready to be put into the answer, there is need for checking the constraints and how many spaces are there to be put.
- By a simple , we can see how many extra e to be added and how many need to put 1 more space.

```cpp=
space= (maxWidth- temp+ row.size())/ (row.size()- 1)- 1;
more= (maxWidth- temp+ row.size())% (row.size()- 1);
```
- Then put into the string one by one and insert more space.

```cpp=
for (int j= 0; j< row.size()- 1; j++)
{
    pack+= row[j]+ " ";
    for (int k= 0; k< space; k++)
        pack+= " ";
    if (more--> 0)
        pack+= " ";
}
pack+= *(row.end()- 1);    
```
- To note, if there is only one word, somply put it inside the string and then add as many space as possible.

```cpp=
pack+= row[0];
while (pack.length()!= maxWidth)
    pack+= " ";
```
- Then push the string into the array and restore the temparay string as empty one.

```cpp=
ans.push_back(pack);   
    pack= "";
        row.clear(); 
```
- When pushing the string into the temparay answer sheet, the following agenda is kept. Since at least 1 space is required, add 1 more space into the count.
```cpp=
temp+= words[i].length()+ 1;
row.push_back(words[i]);
```
- The last one is relatively simple. Add each one with 1 space and leave the rest with spaces.
```cpp=
for (auto &i: row)
{
    pack+= i+ " ";
}
pack+= *(words.end()- 1);
while (pack.length()< maxWidth)
    pack+= " ";
ans.push_back(pack);
```