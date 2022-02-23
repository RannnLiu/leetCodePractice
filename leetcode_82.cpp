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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        dummy -> next = head;
        while(pre -> next){
            ListNode * curr = pre -> next;
            while(curr -> next && curr -> next -> val == curr -> val){
                curr = curr -> next;
            }
            if(curr != pre -> next) pre -> next = curr -> next;
            else pre = pre -> next;
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
        cin >> value;
        build_list(l, value);
    }
    Solution S;
    ListNode* ans = S.deleteDuplicates(l);
    while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}