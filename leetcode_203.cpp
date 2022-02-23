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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *temp = dummy;
        while(temp -> next != NULL){
            if(temp -> next -> val == val){
                temp -> next = temp -> next ->next;
            }
            else temp = temp -> next;
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
    int need_delete;
    cout << "l = ";
    cin >> value;
    ListNode *l = new ListNode(value);
    while(getchar()!='\n'){
       cin >> value;
       build_list(l, value);
    }
    cout <<endl;
    cout << "need delete which value: "<<endl;
    cin >> need_delete;
    Solution S;
    ListNode *ans = S.removeElements(l, need_delete);
    while(ans){
        cout << ans -> val <<endl;
        ans = ans -> next;
    }
    return 0;
}