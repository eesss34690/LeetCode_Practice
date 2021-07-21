class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes='L'+dominoes+'R';
        int n=dominoes.size();
        string ans=dominoes;
        int i = 0;
        while(i<n){
            if(dominoes[i]=='.'){
                int j=i-1;
                while(dominoes[i]=='.'){
                    i++;
                };
                if(dominoes[i]==dominoes[j]){
                    while(j<i){
                        ans[++j]=dominoes[i];
                    }
                }else if(dominoes[i]=='L'){
                    int ii=i;
                    while(j<(i-2)){
                        ans[++j]='R';
                        ans[--i]='L';
                    }
                    i=ii;
                }
            }i++;
        }
        return ans.substr(1,n-2);
    }
};
