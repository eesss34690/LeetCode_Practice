class LRUCache {
public:
    int cap;
    unordered_map<int, vector<int>> mp;
    queue<int> q;
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) != mp.end())
        {
            mp[key][1]++;
            q.push(key);
            return mp[key][0];
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end())
        {
            mp[key][0] = value;
            mp[key][1]++;
            q.push(key);
        }
        else
        {
            mp[key] = {value, 1};
            q.push(key);
        }
        if (mp.size() > cap)
        {
            while (1)
            {
                int cur = q.front();
                q.pop();
                mp[cur][1]--;
                if (mp[cur][1] == 0)
                {
                    mp.erase(cur);
                    break;
                }
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
