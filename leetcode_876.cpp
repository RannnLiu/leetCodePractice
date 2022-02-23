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
    ListNode* middleNode(ListNode* head) {
        int length =getLength(head);
        for(int i = 1; i < (length/2 + 1); ++i){
            head = head -> next;
        }
        return head;
    }
    int getLength(ListNode* head){
        int cnt = 0;
        ListNode *node = head;
        /*
        while(node != NULL){
            cnt++;
            node = node -> next;
        }
        */

        for(node = head; node != NULL; node = node -> next){
            ++cnt;
        }
        return cnt;
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
    curr ->next = l_node;
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
        build_list(l,value);
    }
    /*
    while(l){
        cout << l -> val <<endl;
        l = l -> next;
    }
    */
    Solution S;
    ListNode *ans = S.middleNode(l);
    while(l){
        cout << ans -> val <<endl;
        ans = ans -> next;
    }
    return 0;
}
