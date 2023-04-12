class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res, temp;
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] != '/')
            {
                temp = "";
                while (i < path.size() && path[i] != '/') temp += path[i++];
                if (temp == "..")
                {
                    if(!st.empty()) st.pop();
                }
                else if (temp != ".") st.push(temp);
            }
        }
        if (st.empty()) return "/";
        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res;
    }
};
