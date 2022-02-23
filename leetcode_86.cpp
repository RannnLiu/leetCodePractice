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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* pre = dummy;
        ListNode* curr = head;
        while(pre -> next && pre -> next -> val < x) pre = pre -> next;
        curr = pre;
        while(curr -> next){
            if(curr -> next -> val < x){
                ListNode *tmp = curr -> next;
                curr -> next = tmp -> next;
                tmp -> next = pre -> next;
                pre -> next = tmp;
                pre = pre -> next;
            }
            else curr = curr -> next;
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
    int x;
    cout << "Enter x: " << endl;
    cin >> x;
    cout <<"-----"<<endl;
    Solution S;
    ListNode *ans = S.partition(l, x);
    cout <<"-----"<<endl;
    while(ans){
        cout << ans -> val <<" ";
        ans = ans -> next;
    }
    cout << endl;
    return 0;
}