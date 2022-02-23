#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric(root -> left, root -> right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(left && !right || !left && right || left -> val != right ->val) return false;
        return isSymmetric(left -> left, right -> right) && isSymmetric(left -> right, right -> left);
    }
};

TreeNode* buildtree(TreeNode* root, int val){
    if(root == NULL){
        root = new TreeNode();
        root -> val = val;
        return root;
    }
    if(val < root -> val) 
        root -> left = buildtree(root -> left, val);
    else 
        root -> right = buildtree(root -> right, val);
    return root;
}

void print(TreeNode* root){
  if(root == NULL){
    return;
  }
  cout << root -> val <<" ";
  print(root -> left);
  print(root -> right);
}

int main()
{
    int data;
    cout << "The tree is: ";
    cin >> data;
    TreeNode *root = new TreeNode(data);
    while(getchar() != '\n'){
        cin >> data;
        buildtree(root, data);
    }
    print(root);
    cout << endl;
    Solution S;
    bool ans = S.isSymmetric(root);
    cout << ans;
    return 0;
}