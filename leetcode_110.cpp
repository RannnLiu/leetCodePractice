#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getDepth(root -> left) - getDepth(root -> right)) > 1) return false;
        return isBalanced(root -> left) && isBalanced(root -> right); 
    }
    int getDepth(TreeNode *root){
        if(!root) return 0;
        return 1 + max(getDepth(root -> left), getDepth(root -> right));
    }        
};

void buildtree(TreeNode*& tree){
    char value;
    cin >> value;
    if(value == '#'){
        tree = NULL;
    }
    else{
        tree = new TreeNode;
        tree -> val = value;
        buildtree(tree -> left);
        buildtree(tree -> right);
    }
}

int main()
{
    return 0;
}