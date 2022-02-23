#include <iostream>
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};

int main()
{
    vector <int> preorder_list;
    int pre_tmp;
    cout << "type in the preorder list: ";
    do{
        cin >> pre_tmp;
        preorder_list.insert(preorder_list.end(), pre_tmp);
    }while(getchar() != '\n');
    
    vector <int> inorder_list;
    int in_tmp;
    cout << "type in the inorder list: ";
    do{
        cin >> in_tmp;
        inorder_list.insert(inorder_list.end(), in_tmp);
    }while(getchar() != '\n');

    Solution S;
    TreeNode* ans = buildTree(preorder_list, inorder_list);
    
    return 0;
}