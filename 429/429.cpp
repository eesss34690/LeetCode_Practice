/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<Node*> queue;
    void levelAdd(int size)
    {
        int n= 0;
        vector<int> a;
        for (int i= 0; i< size; i++)
        {
            Node* now= queue[0];
            queue.erase(queue.begin());
            a.push_back(now->val);
            queue.insert(queue.end(), (now->children).begin(), (now->children).end());
            n+= (now->children).size();
        }
        ans.push_back(a);
        if (n)
            levelAdd(n);
    }
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return ans;
        queue.push_back(root);
        levelAdd(1);
        return ans;
    }
};
