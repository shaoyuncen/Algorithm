#include "../common.h"
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* createTree(const vector<int> &vec)
{//存在内存泄露风险，但是可以通过根节点遍历树后逐个节点释放内存
    int size = vec.size();
    if(size == 0)
        return NULL;
    vector<TreeNode*> TreeNodes;
    for (int i = 0; i < size;++i)
    {
        if(vec[i]==NULL)
        {
            TreeNodes.push_back(NULL);
            continue;
        }
        TreeNode *tmp = new TreeNode(vec[i]);
        TreeNodes.push_back(tmp);
    }
    int Tsize = TreeNodes.size();
    for (int i = 0; i < Tsize;++i)
    {
        if(2*i+1<Tsize)
            TreeNodes[i]->left = TreeNodes[2 * i + 1];
        if(2*i+2<Tsize)
            TreeNodes[i]->right = TreeNodes[2 * i + 2];
    }
    return TreeNodes[0];
}
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> line;
            int count = que.size();
            while(count)
            {
                TreeNode* tmp = que.front();
                line.push_back(tmp->val);
                que.pop();
                if(tmp->left)
                    que.push(tmp->left);
                if(tmp->right)
                    que.push(tmp->right);
                count--;
            }
            res.push_back(line);
        }
        return res;
    }
};

int main()
{
    vector<int> TreeVec({3, 9, 20, NULL, NULL, 15, 7});
    TreeNode *TestTree = createTree(TreeVec);
    Solution sol;
    vector<vector<int>> res = sol.levelOrder(TestTree);
    for (int i = 0; i < (int)res.size();++i)
    {
        for (int j = 0; j < (int)res[i].size();++j)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}