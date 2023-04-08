/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> copyMap;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        Node* ans = new Node();
        ans->val = node->val;
        copyMap[ans->val] = ans;
        for (auto &i : node->neighbors)
        {
            if (copyMap.find(i->val) == copyMap.end()) ans->neighbors.push_back(cloneGraph(i));
            else ans->neighbors.push_back(copyMap[i->val]);
        }
        return ans;
    }
};