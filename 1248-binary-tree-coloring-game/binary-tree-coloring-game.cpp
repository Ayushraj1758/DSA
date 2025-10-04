class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    TreeNode* findNode(TreeNode* root, int x) {
        if (!root) return nullptr;
        if (root->val == x) return root;
        TreeNode* left = findNode(root->left, x);
        if (left) return left;
        return findNode(root->right, x);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* nodeX = findNode(root, x);
        int L = countNodes(nodeX->left);
        int R = countNodes(nodeX->right);
        int P = n - (L + R + 1);

        int maxRegion = max({L, R, P});
        return maxRegion > n / 2;
    }
};
