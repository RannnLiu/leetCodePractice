#include<iostream>
#include<vector>
#include<stack>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((p && !q) || (!p && q) || (p -> val != q -> val)) return false;
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q ->right);
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
    else if(val > root -> val)
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
    cout << "The first tree: ";
    cin >> data;
    TreeNode *root1 = new TreeNode(data);
    while(getchar() != '\n'){
        cin >> data;
        buildtree(root1, data);
    }
    print(root1);
    cout << endl;

    cout << "The second tree: ";
    cin >> data;
    TreeNode *root2 = new TreeNode(data);
    while(getchar() != '\n'){
        cin >> data;
        buildtree(root2, data);
    }
    print(root2);
    cout << endl;
    Solution S;
    bool ans = S.isSameTree(root1, root2);
    cout << ans <<endl;
    /*
    cout << "i love you"<<endl;
    TreeNode *root1 = buildtree();
    TreeNode *root2 = buildtree();
    vector<int> c, d;
    cout << "i love you"<<endl;
    //Solution S;
    //bool ans = S.isSameTree(root1, root2);
    
    c = print(root1);
    for(int i = 0; i < c.size(); i++){
        cout << c.at(i) << " ";
    }
    cout << endl;
    cout << "\n root1 is print out"<<endl;
    d = print(root2);
    for(int i = 0; i < d.size(); i++){
        cout << d.at(i) << " ";
    }
    cout << endl;
    //cout << ans;
    */
    return 0;
}


/*
vector<int> print(TreeNode *root){
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* cur = root;
    while(cur || !s.empty()){
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        res.push_back(cur->val);
        cur = cur->left;
    }
    return res;
}
*/ 
