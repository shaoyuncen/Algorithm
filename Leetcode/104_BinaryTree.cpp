#include <iostream>
#include <stack>
#include <queue>
#include <vector> 

using namespace std;
struct BTreeNode
{
	int data;
	BTreeNode *left = NULL;
	BTreeNode *right = NULL;
};

class BTree
{
public:
	BTree(vector<int> &_nums) {
		nums = _nums;
		root = NULL;
		index = 0;
	}
	BTreeNode* createBTree();
	BTreeNode* createBTree2();
	void createBTree2(BTreeNode* root,int index2);

	//前序遍历(递归)  
	void preOrder(BTreeNode* root);
	//前序遍历(非递归)  
	void NotRePreOrder();

	//中序遍历(递归)  
	void inOrder(BTreeNode* root);
	//中序遍历(非递归)  
	void NotReInOrder();

	//后序遍历(递归)  
	void postOrder(BTreeNode* root);
	//后序遍历(非递归)  
	void NotRePostOrder();

	//求结点个数  
	int BTreeSize();
	//求叶子结点个数  
	int BTreeLeaves();

	//求树高  
	int DFS_Height(BTreeNode *root);
	//层次法求树高  
	int BFS_Height(BTreeNode *root);

//private:
	BTreeNode* root;
	vector<int> nums;
	unsigned int index;
};

//建立二叉树的算法 层次遍历 非递归  
BTreeNode* BTree::createBTree()
{
	BTreeNode* temp = NULL;
	if (nums.size() == 0) return NULL;

	vector<BTreeNode*> q;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		BTreeNode* p = NULL;
		p = new BTreeNode;
		p->data = nums[i];
		q.push_back(p);
	}
	temp = q[0];
	unsigned int loop = 1;
	unsigned int index = 0;
	while (index < q.size())
	{
		for (unsigned int i = 0; i < loop && index < q.size(); i++)
		{
			index = loop - 1 + i;
			if(2 * index + 1 < q.size())	
				q[index]->left = q[2 * index + 1];
			if(2 * index + 2 < q.size())
				q[index]->right = q[2 * index + 2];
		}
		loop *= 2;
	}
	return temp;
}
//建立二叉树的算法 层次遍历 递归  
BTreeNode* BTree::createBTree2() {
	BTreeNode* temp=new BTreeNode;
	createBTree2(temp, 0);
	this->root = temp;
	return temp;
}
void BTree::createBTree2(BTreeNode* root,int index2) {
	if (index2 >= nums.size()) {
		//delete root;
		root = NULL;
	}
	else {
		//root = new BTreeNode;
		root->data = nums[index2];
		if ((index2 * 2 + 1) < nums.size()) {
			root->left = new BTreeNode;
			createBTree2(root->left, index2 * 2 + 1);
		}
		if ((index2 * 2 + 2) < nums.size()) {
			root->right = new BTreeNode;
			createBTree2(root->right, index2 * 2 + 2);
		}
	}
}
//递归法
void BTree::preOrder(BTreeNode* root) {
	if (root == NULL)
		return;
	else if (root->data == -1) {
		return;
	}
	else
	{
		cout << root->data << ' ';
		preOrder(root->left);
		preOrder(root->right);
	}
}
void BTree::inOrder(BTreeNode* root) {
	//BTreeNode* temp=NULL;
	if (root==NULL)
		return;
	else if (root->data == -1) {
		return;
	}
	else
	{
		inOrder(root->left);
		cout << root->data << ' ';
		inOrder(root->right);
	}
}
void BTree::postOrder(BTreeNode* root) {
	//BTreeNode* temp=NULL;
	if (root == NULL)
		return;
	else if (root->data == -1) {
		return;
	}
	else
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << ' ';
	}
}
int BTree::DFS_Height(BTreeNode *root)
{
	return root == NULL ? 0 : max(DFS_Height(root->left), DFS_Height(root->right)) + 1;
}
int BTree::BFS_Height(BTreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<BTreeNode *> q;
        int count = 0;
        q.push(root);
        while (!q.empty())
        {
            count++;
            for (unsigned int i = 0; i < q.size(); i++)
            {
                BTreeNode *p = q.front();
                q.pop();
                if (p->left != NULL)
                {
                    q.push(p->left);
                }
                if (p->right != NULL)
                {
                    q.push(p->right);
                }
            }
        }
        return count;
    }


int main()
{
	vector<int> nums = {3, 9,  15, -1, -1,  7, 20};
	BTree T(nums);
	BTreeNode* root=T.createBTree();
	T.preOrder(root);
	cout << endl;
	T.inOrder(root);
	cout << endl;
	T.postOrder(root);
	cout << endl;
	int count = T.DFS_Height(root);
	cout << count << endl;
	int count2 = T.BFS_Height(root);
	cout << count2 << endl;
	return 0;
}
