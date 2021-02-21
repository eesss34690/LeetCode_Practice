class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss(version1);
        string temp;
        vector<int>res1;
        vector<int>res2;
        while(getline(ss,temp,'.')){
            if(temp.size()==0) continue;
            int sum=0;
            for(int i=0;i<temp.size();i++){
                sum=(sum*10)+(temp[i]-'0');
            }
            res1.push_back(sum);
        }
        stringstream ss2(version2);
        while(getline(ss2,temp,'.')){
            if(temp.size()==0) continue;
            int sum=0;
            for(int i=0;i<temp.size();i++){
                sum=(sum*10)+(temp[i]-'0');
            }
            res2.push_back(sum);
        }
        int i=0;
        int j=0;
        while(i<res1.size() && j<res2.size()){
            if(res1[i]>res2[j]) return 1;
            else if(res2[j]>res1[i]) return -1;
            else{
                i++;j++;
            }
        }
        while(i<res1.size()){
            if(res1[i]!=0) return 1;
            i++;
        }
        while(j<res2.size()){
            if(res2[j]!=0) return -1;
            j++;
        }
        return 0;
    }
};