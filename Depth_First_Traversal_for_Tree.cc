//Linear data structures have only one logical way to traverse them
//Unlike them, trees can be traversed in different ways
//(1) Depth First Traversal : a) Inorder b) Preorder c) Postorder
//(2) Breath First Traversal
//(3) Level order Traversal

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Traversal {
public:
    vector<int> Inorder(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        TreeNode *cur = root;
        while(cur || !stk.empty()) {
            if(cur) {
                stk.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode* node = stk.top();
                stk.pop();
                ret.push_back(node->val);
                if(node->right) cur = node->right;
            }
        }
        return ret;
    }
    
    vector<int> Preorder(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            if(!node) continue;
            ret.push_back(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        return ret;
    }
    
    vector<int> Postorder(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        TreeNode *cur = root, *last = NULL;
        while(cur || !stk.empty()) {
            if(cur) {
                stk.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode* node = stk.top();
                if(node->right && last != node->right)
                    cur = node->right;
                else {
                    ret.push_back(node->val);
                    stk.pop();
                    last = node;
                }
            }
        }
        return ret;
    }
    
    vector<int> InorderRe(TreeNode* root) {
        vector<int> ret;
        InorderDFS(root, ret);
        return ret;
    }
    
    void InorderDFS(TreeNode* root, vector<int>& ret) {
        if(!root) return;
        InorderDFS(root->left, ret);
        ret.push_back(root->val);
        InorderDFS(root->right, ret);
    }
    
    vector<int> PreorderRe(TreeNode* root) {
        vector<int> ret;
        PreorderDFS(root, ret);
        return ret;
    }
    
    void PreorderDFS(TreeNode* root, vector<int>& ret) {
        if(!root) return;
        ret.push_back(root->val);
        PreorderDFS(root->left, ret);
        PreorderDFS(root->right, ret);
    }
    
    vector<int> PostorderRe(TreeNode* root) {
        vector<int> ret;
        PostorderDFS(root, ret);
        return ret;
    }
    
    void PostorderDFS(TreeNode* root, vector<int>& ret) {
        if(!root) return;
        PostorderDFS(root->left, ret);
        PostorderDFS(root->right, ret);
        ret.push_back(root->val);
    }
};

void show(vector<int>& vec) {
    for(auto v : vec)
        cout << v << " ";
    cout << endl;
}

int main()
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    Traversal traversal;
    vector<int> ret;
    ret = traversal.Inorder(&n1);
    show(ret);
    ret = traversal.InorderRe(&n1);
    show(ret);
    ret = traversal.Preorder(&n1);
    show(ret);
    ret = traversal.PreorderRe(&n1);
    show(ret);
    ret = traversal.Postorder(&n1);
    show(ret);
    ret = traversal.PostorderRe(&n1);
    show(ret);
    return 0;
}
