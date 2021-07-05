class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len=words[0].length();
        int num_words=words.size();
        if(s.length()<(len*num_words)) return {};
        unordered_map<string,int> og_count;
        for(auto i:words){
            og_count[i]++;
        }
        vector<int> answer;
        for(int i=0;i<=s.length()-(num_words*len);i++){
            string check=s.substr(i,num_words*len);
            unordered_map<string,int> count;
            int j=0;
            for(;j<check.length();j+=len){
                string temp=check.substr(j,len);
                if(og_count.find(temp)==og_count.end()) break;
                if(count[temp]==og_count[temp]) break;
                count[temp]++;
            }
            if(j==check.length()) answer.push_back(i);
        }
        return answer;
    }
        
};