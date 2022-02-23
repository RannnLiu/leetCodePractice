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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy -> next = head;
        for(int i = 0; i < left-1; ++i) pre = pre -> next;
        ListNode *curr = pre -> next;
        for(int i = left; i < right; ++i){
            ListNode *t = curr -> next;
            curr -> next = t -> next;
            t -> next = pre -> next;
            pre -> next = t;
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

int main(){
    int value;
    cout << "l = ";
    cin >> value;
    ListNode *l = new ListNode(value);
    while(getchar()!='\n'){
        cin >> value;
        build_list(l, value);
    }
    int n, m;
    cout <<"Enter m and n: ";
    cin >> m;
    cin >> n;
    Solution S;
    ListNode *ans = S.reverseBetween(l, m, n);
    while(ans){
        cout << ans -> val <<" ";
        ans = ans -> next;
    }
    cout << endl;
    return 0;
}