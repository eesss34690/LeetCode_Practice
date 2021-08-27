class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> temp;
        queue<string> waiting;
        auto pos= preorder.find(",");
        while (1)
        {
            temp.push_back(preorder.substr(0, pos));
            if (pos== string::npos)
                break;
            preorder= preorder.substr(pos+ 1, string::npos);
            pos= preorder.find(",");
        }
        int ind= 0;
        string target;
        waiting.push(temp[0]);
        while (!waiting.empty())
        {
            target= waiting.front();
            waiting.pop();
            if (target!= "#")
            {
                if (ind+ 2< temp.size())
                {
                    waiting.push(temp[++ind]);
                    waiting.push(temp[++ind]);
                }
                else
                    return false;
            }
        }
        if (ind== temp.size()- 1)
            return true;
        return false;
    }
};
