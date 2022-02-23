#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        dummy -> next = head;
        while(pre -> next && pre -> next -> next){
            ListNode* temp = pre -> next -> next;
            pre -> next -> next = temp -> next;
            temp -> next = pre -> next;
            pre -> next = temp;
            pre = temp -> next;
        }
        return dummy -> next;
    }
};

ListNode *build_list(ListNode *l, int value){
    ListNode *l_node = new ListNode();
    l_node -> val = value;
    l_node -> next = NULL;
    ListNode *curr = l;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = l_node;
    return l;
} 

int main()
{
    int value;
    cout << "l = ";
    cin >> value;
    ListNode *l = new ListNode(value);
    while(getchar()!='\n'){
        cin >>value;
        build_list(l, value);
    }
    Solution S;
    ListNode *ans = S.swapPairs(l);
    while(ans){
        cout << ans -> val << " ";
        ans = ans -> next;
    }
    cout << endl;
    return 0;
}