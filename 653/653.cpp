class Solution {
public:
    TreeNode* rot;
    bool find_(TreeNode* root, int k)
    {
        if (root-> val== k)
            return true;
        if (root-> val< k)
        {
            if (root-> right!= NULL&& find_(root-> right, k))
                return true;
        }
        else if (root-> left!= NULL&& find_(root-> left, k))
            return true;
        return false;
    }
    bool treverse(TreeNode* root, int k)
    {
        if (k- root->val!= root->val&& find_(rot, k- root->val))
            return true;
        if (root-> left!= NULL)
        {
            if (treverse(root-> left, k))
                return true;
        }
        if (root-> right!= NULL)
        {
            if (treverse(root-> right, k))
                return true;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        rot= root;
        return treverse(rot, k);
        
    }
};
