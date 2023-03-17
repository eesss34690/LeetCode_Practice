struct TrieNode {
    TrieNode* child[26];
    bool hasVal = false;
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        auto cur = root;
        for (auto &i : word)
        {
            if (cur->child[i - 'a'] == NULL)
                cur->child[i - 'a'] = new TrieNode();
            cur = cur->child[i - 'a'];
        }
        cur->hasVal = true;
    }

    bool search(string word) {
        auto cur = root;
        for (auto &i : word)
        {
            if (cur->child[i - 'a'] == NULL) return false;
            cur = cur->child[i - 'a'];
        }
        return cur->hasVal;
    }

    bool startsWith(string prefix) {
        auto cur = root;
        for (auto &i : prefix)
        {
            if (cur->child[i - 'a'] == NULL) return false;
            cur = cur->child[i - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
