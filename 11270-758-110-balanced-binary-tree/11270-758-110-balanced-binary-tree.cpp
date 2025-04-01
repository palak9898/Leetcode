class Solution {
public:
    int checkHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1){
            return -1;
        }
        int rightHeight = checkHeight(root->right);
        if(rightHeight == -1){
            return -1;
        }
        if(abs(leftHeight - rightHeight) > 1){
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1; // FIXED: It should be != -1, not != 1
    }
};
