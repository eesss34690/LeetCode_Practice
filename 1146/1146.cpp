class SnapshotArray {
public:
    vector<vector<pair<int, int>>> shot;
    int id;
    SnapshotArray(int length) {
        shot.resize(length);
        id = 0;
    }
    
    void set(int index, int val) {
        if (!shot[index].empty() && shot[index].back().first == id) shot[index].back().second = val;
        else shot[index].push_back(make_pair(id, val));
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto temp = upper_bound(shot[index].begin(), shot[index].end(), make_pair(snap_id, INT_MAX));
        if (temp == shot[index].begin()) return 0;
        return (temp - 1)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */