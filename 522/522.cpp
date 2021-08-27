int findLUSlength(vector<string>& strs) {
      int n = strs.size(), len = -1;                 
      for(int i=0; i<n; i++){
        bool poss = true;
        for(int j=0; j<n; j++){
          if(i == j)  continue;
          if(lcs(strs[i], strs[j])){
            poss = false;
            break;
          }                     
        }
        if(poss)
          len = max(len, (int)strs[i].size());              
      }
      return len;              
    }
  bool lcs(string a, string b){
    int n = a.size(), m = b.size(), i = 0;
    if(n > m)
      return false;
    for(int j=0; j < m; j++){
      if(a[i] == b[j]){
        i++;
        if(i == n)  return true;
      }
    }
    return false;
  }
