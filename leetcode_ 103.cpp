#include <iostream>
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

void create_tree(TreeNode* &tree){
    int data;
    cin >> data;
    if(data != '\n'){
        if(data == -1){
            tree = nullptr;
        }
        else{
            tree = new TreeNode();
            tree -> val = data;
            create_tree(tree -> left);
            create_tree(tree -> right);
        }
    }
}

/*
void print_tree(TreeNode* &tree){

}
*/

class Solution {
public:
    //交叉往返的之字形的层序遍历
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector <vector <int> > res;
        queue<TreeNode* > q{{root}}; //二维
        int cnt = 0;
        while(!q.empty()){
            vector <int> onelevel;
            for(int i = q.size(); i > 0; --i){
                TreeNode *t = q.front();
                q.pop();
                onelevel.push_back(t -> val);
                if(t -> left) q.push(t -> left);
                if(t -> right) q.push(t -> right);
            }
            if(cnt % 2 == 1) reverse(onelevel.begin(), onelevel.end());
            res.push_back(onelevel);
            ++cnt; 
        }
        return res;
    }
};

int main()
{
    TreeNode* tree;
    create_tree(tree);

    return 0;
}