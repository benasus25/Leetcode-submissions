class Solution {
public:
    TreeNode* buildTree(vector<int>& P, vector<int>& I) {
        unordered_map<int, int> M;
        for (int i = 0; i < I.size(); i++)
            M[I[i]] = i;
        return splitTree(P, M, 0, 0, I.size()-1);
    }
    
private:
    
    int pix = 0;
    
    TreeNode* splitTree(vector<int>& P, unordered_map<int, int>& M, int pix, int ileft, int iright) {
        int rval = P[pix], imid = M[rval];
        TreeNode* root = new TreeNode(rval);  
        pix++;
        if (imid > ileft)
            root->left = splitTree(P, M, pix, ileft, imid-1);
        if (imid < iright)
            root->right = splitTree(P, M, pix+imid-ileft, imid+1, iright);
        return root;
    }
};