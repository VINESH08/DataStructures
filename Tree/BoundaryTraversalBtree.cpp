#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;
};
class Btraverasal
{
public:
    TreeNode *newnode;
    TreeNode *create(int val)
    {
        newnode = new TreeNode();
        newnode->val = val;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    bool isLeaf(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    void addLeftBoundary(TreeNode *root, vector<int> &result)
    {
        TreeNode *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
            {
                result.push_back(curr->val);
            }
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    void addRightBoundary(TreeNode *root, vector<int> &result)
    {
        TreeNode *curr = root->right;
        vector<int> tmp;
        while (curr)
        {
            if (!isLeaf(curr))
                tmp.push_back(curr->val);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            result.push_back(tmp[i]);
        }
    }
    void addLeaves(TreeNode *root, vector<int> &result)
    {
        if (root == NULL)
            return;
        if (isLeaf(root))
        {
            result.push_back(root->val);
        }
        if (root->left)
        {
            addLeaves(root->left, result);
        }
        if (root->right)
            addLeaves(root->right, result);
    }
};
int main()
{
    Btraverasal obj;
    TreeNode *root;
    vector<int> result;
    root = obj.create(1);
    root->left = obj.create(2);
    root->right = obj.create(5);
    root->right->left = obj.create(6);
    root->left->left = obj.create(3);
    root->left->right = obj.create(4);
    result.push_back(root->val);
    obj.addLeftBoundary(root, result);
    obj.addLeaves(root, result);
    obj.addRightBoundary(root, result);
    for (int i : result)
    {
        cout << i << ' ';
    }
}