class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0.0;
        for (auto &i : salary) ans += i;
        return (ans - *max_element(salary.begin(), salary.end()) - *min_element(salary.begin(), salary.end())) / (salary.size() - 2);
    }
};
