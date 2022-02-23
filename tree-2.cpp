#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void build(vector<int> list, TreeNode* root, int position){
    if(position == 0){
        root->val = list.at(0);
    }
    if(position*2 < list.size()){
        if(position*2+1 < list.size()){
            root->left = new TreeNode(list.at(position*2+1));
            build(list, root->left, position*2+1);
        }
        if(position*2+2 < list.size()){
            root->right = new TreeNode(list.at(position*2+2));
            build(list, root->right, position*2+2);
        }
    }
    return;
}

void print(TreeNode* root){
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        for(int i = q.size(); i > 0; i--){
            TreeNode* t = q.front();
            q.pop();
            cout << t->val << " ";
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
}

int main(){
    vector<int> list;
    for(int i = 1; i < 6; i++){
        list.insert(list.end(), i);
    }
    TreeNode* root = new TreeNode();
    build(list, root, 0);
    print(root);
    cout << endl;
    return 0;
}