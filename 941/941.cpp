class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int idx = 1;
        if (arr.size() == 1) return false;
        while(idx < arr.size() && arr[idx] > arr[idx - 1]) idx++;
        if (idx == 1 || idx == arr.size() || arr[idx] == arr[idx - 1]) return false;
        while(idx < arr.size() && arr[idx] < arr[idx - 1]) idx++;
        if(idx != arr.size()) return false;
        return true;
    }
};