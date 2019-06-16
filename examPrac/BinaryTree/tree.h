
class TreeNode{
public:
    TreeNode(int rootValue):val(rootValue){}
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int val;
};
class BinaryTree{
public:
    BinaryTree(int rootValue);
    ~BinaryTree();
    bool insertNodeWithValue(int value);
    bool deleteNodeWithValue(int value);
    void printTree();
private:
    TreeNode* root;
};
void visit(TreeNode* root)
{
    
}

void inOrderTraversal(TreeNode* root)
{
    if(!root)
        return;
    inOrderTraversal(root->left);
    visit(root);
    inOrderTraversal(root->right);
}
void postOrderTraversal(TreeNode* root)
{
    if(!root)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    visit(root);
}