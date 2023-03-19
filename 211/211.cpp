class WordDictionary {
public:
    struct alphalete {
        alphalete* next[26];
        bool isLast = false;
    };
    alphalete* root;
    WordDictionary() {
        root = new alphalete();
    }

    void addWord(string word) {
        alphalete* temp = root;
        for (auto &i : word)
        {
            if (temp->next[i - 'a'] == NULL)
                temp->next[i - 'a'] = new alphalete();
            temp = temp->next[i - 'a'];
        }
        temp->isLast = true;
    }

    bool searchSubIndex(string& word, alphalete* i, int index) {
        for (int j = index; j < word.length(); j++) {
            if (word[j] == '.') {
                for (auto &c: i->next)
                    if (c && searchSubIndex(word, c, j + 1)) return true;
                return false;
            }
            int idx = word[j] - 'a';
            if (i->next[idx] == NULL) return false;
            i = i->next[idx];
        }
        return i->isLast;
    }

    bool search(string word) {
        return searchSubIndex(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
