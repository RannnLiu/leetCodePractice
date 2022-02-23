#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
TreeNode *CreateBiTree(){
    int data;
    TreeNode* Tree;
    cin >> data;
    if(data == -1)
        Tree = NULL;
    else {
        Tree = new TreeNode;
        Tree -> val = data;
        Tree -> left = CreateBiTree();
        Tree -> right = CreateBiTree();
    }
    return Tree;
}
*/

class Solution {
public:
    //99
    //inorder遍历一遍，把结果的点存在list里，把点的值存在val里
    //O(n)
    void recoverTree(TreeNode* root) {
        vector <TreeNode*> list;
        vector <int> vals;
        inorder(root, list, vals);
        sort(vals.begin(), vals.end());
        for(int i = 0; i < list.size(); ++i){
            list[i] -> val = vals[i];
        }
    }
    void inorder(TreeNode* root, vector<TreeNode*>& list, vector<int>& vals){
        if(!root) return;
        inorder(root -> left, list, vals);
        list.push_back(root);
        vals.push_back(root -> val);
        inorder(root -> right, list, vals);
    }

    //98
    //Recursion
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> vals;
        in_order(root, vals);
        for(int i = 0; i < vals.size() - 1; ++i){
            if(vals[i] >= vals[i + 1]) return false;
        }
        return true;
    }
    void in_order(TreeNode* root, vector<int> &vals){
        if(!root) return;
        in_order(root -> left, vals);
        vals.push_back(root -> val);
        in_order(root -> right, vals);
    }
};
/*
TreeNode* build(TreeNode* root, int val){
    if(root == NULL){
        root = new TreeNode();
        root -> val = val;
        return root;
    }
    if(val < root -> val) 
        root -> left = build(root -> left, val);
    else if(val > root -> val)
        root -> right = build(root -> right, val);
    return root;
}

void level_order(TreeNode* root){
    queue <TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        cout << val << " ";
        if(temp -> left)
            q.push(temp -> left);
        if(temp -> right) 
            q.push(temp -> right);
    }
}
*/

int main()
{
    TreeNode* root = NULL;
    int t[] = {5, 4, 6, 3, 7};
    for(int i = 0; i < 5; ++i)
        root = build(root, t[i]);
    level_order(root);
    return 0;
}