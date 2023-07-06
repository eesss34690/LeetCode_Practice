# 273_Integer_to_English_Words
###### tags: `leetcode` `273`
## Problem Statement
Convert a non-negative integer num to its English words representation.

- Example 1:

> Input: num = 123
Output: "One Hundred Twenty Three"
- Example 2:

> Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
- Example 3:

> Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
- Example 4:

> Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 
- Constraints:

> 0 <= num <= 2^31^ - 1
## Solution
- Append a function for dealing with number smaller than 100, ```add2```.
- If the number if between ```10``` to ```19```, the this is the ```teen``` catagory.
- Else, need to see whether it is bigger than 10 to see whether to add the ```-ty``` word.

```cpp=
 void add2(char a, char b)
{
    if (a== '1')
        ans.push_back(ten.find(b)->second);
        
    else if (a!= '0')
    {
        if (b!= '0')
            ans.push_back(normal.find(b)->second);
    
        ans.push_back(ty.find(a)->second);
    }
    else if (b!= '0')
        ans.push_back(normal.find(b)->second);
    }
```
- The ```map``` attributes are the strings.

```cpp=
map<char, string> normal;
map<char, string> ty;
map<char, string> ten;
normal['1']= "One";
normal['2']= "Two";
normal['3']= "Three";
//......
ten['1']= "Eleven";
ten['2']= "Twelve";
ten['3']= "Thirteen";
//......
ty['2']= "Twenty";
ty['3']= "Thirty";
ty['4']= "Forty";
```
- Remember to reverse the integer for computation.

```cpp=
string n= to_string(num);
reverse(begin(n), end(n));
```
- In the following for-loop, need to deal with value bigger than 100 and add the big value attribute.
- ```temp``` is the index controller for the attribute.

```cpp=
string eng[]= {"Thousand", "Million", "Billion"};
for (int i= 2; i< n.length(); i+= 3)
{
    if (n[i]== '0'&& n[i- 1]== '0'&& n[i- 2]== '0')
    {
        temp++;
        continue;
    }
    if (i!= 2)
        ans.push_back(eng[temp++]);
    else
        temp++;
    add2(n[i- 1], n[i- 2]);
    if (n[i]!= '0')
    {
        ans.push_back("Hundred");
        ans.push_back(normal.find(n[i])->second);
    }
}
```
- Add the last one, is needed when there is leftover for 3 divison.

```cpp=
if (n.length()% 3== 2)
{
    if (temp!= -1)
        ans.push_back(eng[temp]);
    add2(*(n.end()- 1), *(n.end()- 2));
}
else if (n.length()% 3== 1)
{
    if (temp!= -1)
        ans.push_back(eng[temp]);
    add2('0', *(n.end()- 1));
}
```
- Put the strings in the answer sheet in reverse order, remember to add space in beween.

```cpp=
for (vector<string>::iterator i= ans.end()- 1; i!= ans.begin(); i--)
{
    aa+= *i;
    aa+= " ";
}
aa+= ans[0];
return aa;
```