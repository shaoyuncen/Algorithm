#include <queue>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        queue<Node*> currLevel, nextLevel;
        currLevel.push(root);
        while(!currLevel.empty())
        {
            Node* currNode = currLevel.front();
            currLevel.pop();
            if(currNode)
            {
                if(!currLevel.empty())
                    currNode->next = currLevel.front();
                nextLevel.push(currNode->left);
                nextLevel.push(currNode->right);
            }
            if(currLevel.empty())
            {
                swap(currLevel, nextLevel);
            }
        }
        return root;
    }
};