class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i= 0; i< ransomNote.length(); i++)
        {
            size_t found= magazine.find(ransomNote[i]);
            if (found== -1)
                return false;
            magazine.erase(found, 1);
        }
        return true;
    }
};