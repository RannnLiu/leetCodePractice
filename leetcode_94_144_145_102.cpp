#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    //94
    //Non - recursion
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p = p -> left;
            }
            p = s.top();
            s.pop();
            res.push_back(p -> val);
            p = p -> right;
        }
        return res;
    }

    //recursion
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    } 
    void inorder(TreeNode *root, vector<int> &res){
        if(!root) return;
        if(root -> left) inorder(root -> left, res);
        res.push_back(root -> val);
        if(root -> right) inorder(root -> right, res);
    }

    //144
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while(!st.empty() || p){
            if(p){
                st.push(p);
                res.push_back(p -> val);
                p = p -> left;
            }
            else{
                p = st.top();
                st.pop();
                p = p -> right;
            }
        }
        return res;
    }

    //145
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > s;
        TreeNode *p = root;
        while(p || !s.empty()){
            if(p){
                s.push(p);
                res.insert(res.begin(), p -> val);
                p = p -> right;
            }
            else{
                TreeNode *t = s.top();
                s.pop();
                p = t -> left;
            }
        }
        return res;
    }

    //102
    //recursion
    vector< vector <int> > levelOrder(TreeNode* root) {
        vector<vector <int> > res;
        level_order(root, 0, res);
        return res;
    }
    void level_order(TreeNode* node, int level, vector<vector <int> >& res){
        if(!node) return;
        if(res.size() == level) res.push_back({});
        res[level].push_back(node -> val);
        if(node -> left) level_order(node -> left, level + 1, res);
        if(node -> right) level_order(node -> right, level + 1, res);
    }
};


void build_tree(vector<int> list, TreeNode* root, int position){
    if(position == 0){
        root -> val = list.at(0);
    }
    if(position * 2 < list.size()){
        if(position * 2 + 1 < list.size()){
            root -> left = new TreeNode(list.at(position * 2 + 1));
            build_tree(list, root -> left, position * 2 + 1);
        }
        if(position * 2 + 2 > list.size()){
            root -> right = new TreeNode(list.at(position * 2 + 2));
            build_tree(list, root -> right, position * 2 + 2);
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
            cout << t -> val << " ";
            if(t -> left) q.push(t -> left);
            if(t -> right) q.push(t -> right);
        }
    }
}

int main()
{
    int data;
    cout << "The tree is: ";
    cin >> data;
    vector<int> list;
    TreeNode *root = new TreeNode(data);
    while(getchar() != '\n'){
        cin >> data;
        build_tree(list, root, 0);
    }
    print(root);
    cout << endl;
    return 0;
}
