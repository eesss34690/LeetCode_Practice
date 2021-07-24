class Solution {
public:
        struct Pair {
            string s;
            vector<string> curr;
            Pair(string _s, vector<string> _curr) {
                s=_s;
                curr=_curr;
            }
        };
    bool differsByOne(string s, string t) {
        int c=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]!=t[i])  c++;
            if(c>1) break;
        }
        return c==1;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};
        
        auto it=find(wordList.begin(), wordList.end(), beginWord);
        if(it != wordList.end()) wordList.erase(it);
        
        int n=wordList.size();
        
        queue<Pair> q;
        q.push({beginWord,{beginWord}});
        unordered_map<string, bool> vis;
        
        vector<vector<string>> ans;
        int mx=1002;
        while(!q.empty()) {
            string str=q.front().s;
            vector<string> currAns=q.front().curr;
            q.pop();
            
            if(str==endWord && currAns.size()<=mx) {
                mx=currAns.size();
                ans.push_back(currAns);
            } 
            vis[str]=1;                                        
            for(int i=0;i<n;i++) {
                if(!vis.count(wordList[i]) && differsByOne(str, wordList[i])) {
                    currAns.push_back(wordList[i]);
                    q.push({wordList[i], currAns});
                    currAns.pop_back();
                }
            }
            
        }
        return ans;
    }
};
