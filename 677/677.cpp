class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> pairs;
    MapSum() {
    }
    
    void insert(string key, int val) {
        pairs[key]= val;
    }
    
    int sum(string prefix) {
        int len= prefix.length(), ans= 0;
        for (auto i= pairs.begin(); i!= pairs.end(); i++)
        {
            if (len<= (i->first).length()&& (i->first).substr(0,len)== prefix)
            {
                ans+= i->second;
            }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
