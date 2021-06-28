class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        long long int sum= accumulate(arr.begin(), arr.end(), 0);
        if (sum<= target)
            return *(arr.end()-1);
        for (int i= arr.size()- 1; i> 0; i--)
        {
            sum-= (arr.size()- i)* (arr[i]- arr[i- 1]);
            //cout<<arr[i]<<": "<<sum<<endl;
            if (target>= sum&& target- sum< (arr.size()- i)/2)
            {
                //cout<<"a: "<<sum<<endl;
                return arr[i- 1];
            }
            else if (target> sum)
            {
                int j= (target- sum)/ (arr.size()- i);
                if (target- sum- j* (arr.size()- i)> (arr.size()- i)/ 2)
                    j++;
                //cout<<"b: "<<sum<<" "<<j;
                return arr[i- 1]+ j;
            }
            else if (sum- target< arr.size()- i)
            {
                //cout<<"c: "<<sum<<endl;
                return arr[i- 1];
            }
            //cout<<endl;
        }
        //cout<<"end"<<sum<<" "<<target/ arr.size();
        if (target- (target/ arr.size())* arr.size()> arr.size()/ 2)
            return target/ arr.size()+ 1;
        return target/ arr.size();
    }
};