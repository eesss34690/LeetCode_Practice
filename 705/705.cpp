class MyHashSet {
public:
    unordered_set<int> table;
    MyHashSet() {

    }

    void add(int key) {
        table.insert(key);
    }

    void remove(int key) {
        auto temp = find(table.begin(), table.end(), key);
        if ( temp != table.end()) table.erase(temp);
    }

    bool contains(int key) {
        return find(table.begin(), table.end(), key) != table.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
