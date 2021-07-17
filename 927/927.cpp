class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> ind, ans;
        ans.push_back(-1);
        ans.push_back(-1);
        for(int i= 0; i< arr.size(); i++)
        {
            if(arr[i])
                ind.push_back(i);
        }
        if (ind.size()% 3)
            return ans;
        if (!ind.size())
        {
            ans[0]= arr.size()/ 3- 1;
            ans[1]= arr.size()- 1;
            return ans;
        }
        int por= ind.size()/ 3;
        int a= ind[0], b= ind[por], c= ind[por* 2];
        vector<int> three(c+ arr.begin(), arr.end());
        int d= three.size();
        vector<int> one(a+ arr.begin(), a+ d+ arr.begin());
        vector<int> two(b+ arr.begin(), b+ d+ arr.begin());
        if (one== two&& one== three)
        {
            ans[0]= a+ d- 1;
            ans[1]= b+ d;
        }
        return ans;
    }
};
