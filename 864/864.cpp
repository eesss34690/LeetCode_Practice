class Solution {
    struct State {
        int keys, i, j;
        State(int keys, int i, int j) : keys(keys), i(i), j(j) {}
    };
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int x = -1, y = -1, totalKeys = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].length(); j++) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') totalKeys++;
                else if (grid[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        State start(0, x, y);
        queue<State> q;
        unordered_set<string> visited;
        visited.insert(to_string(0) + " " + to_string(x) + " " + to_string(y));
        q.push(start);
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int step = 0, size, i, j, keys;
        while (!q.empty()) {
            size = q.size();
            while (size-- > 0) {
                State cur = q.front();
                q.pop();
                if (cur.keys == (1 << totalKeys) - 1) return step;
                for (auto dir : dirs)
                {
                    i = cur.i + dir[0];
                    j = cur.j + dir[1];
                    keys = cur.keys;
                    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size())
                    {
                        if (grid[i][j] == '#') continue;
                        if (grid[i][j] >= 'a' && grid[i][j] <= 'f') keys |= 1 << (grid[i][j] - 'a');
                        if (grid[i][j] >= 'A' && grid[i][j] <= 'F' && ((keys >> (grid[i][j] - 'A')) & 1) == 0) continue;
                        if (visited.find(to_string(keys) + " " + to_string(i) + " " + to_string(j)) == visited.end())
                        {
                            visited.insert(to_string(keys) + " " + to_string(i) + " " + to_string(j));
                            q.push(State(keys, i, j));
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
