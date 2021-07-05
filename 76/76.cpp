class Solution {
public:
    string minWindow(string& s, string& t) {
        int c[52]={},ans=INT_MAX,ansl=0;
        for(auto& ch:t)
            c[getI(ch)]++;
        for(int l=0,r=0,total=t.length();s[r];++r){
            if(--c[getI(s[r])]>=0)
                total--;
            while(l<=r && c[getI(s[l])]<0)
                c[getI(s[l++])]++;
            if(total==0 && ans>r-l+1)
                ans=r-l+1,ansl=l;
        }
        return (ans==INT_MAX)?"":s.substr(ansl,ans);
    }
private:
    int getI(char ch) {
        return ch-65-((ch>=97)?6:0);
    }
};