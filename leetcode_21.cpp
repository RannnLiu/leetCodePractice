#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if(!l1) return l2;
       if(!l2) return l1;
       if(l1 -> val <= l2 -> val){
           l1 -> next = mergeTwoLists(l1 -> next, l2);
           return l1;
       }
       else {
           l2 -> next = mergeTwoLists(l2 -> next, l1);
           return l2;
       }
    }
};

/*
ListNode *build_list_1(int test){
    ListNode *l1 = new ListNode();
    if(test == 1){
        ListNode *l1_node1 = new ListNode();
        ListNode *l1_node2 = new ListNode();
        l1 -> val = 1;
        l1_node1 -> val = 2;
        l1_node2 -> val = 4;
        l1 -> next = l1_node1;
        l1_node1 -> next = l1_node2; 
        l1_node2 -> next = NULL;
    }
    return l1;
}

ListNode *build_list_2(int test){
    ListNode *l2 = new ListNode();
    if(test == 1){
        ListNode *l2_node1 = new ListNode();
        ListNode *l2_node2 = new ListNode();
        l2 -> val = 1;
        l2_node1 -> val = 2;
        l2_node2 -> val = 4;
        l2 -> next = l2_node1;
        l2_node1 -> next = l2_node2; 
        l2_node2 -> next = NULL;
    }
    return l2;
}
*/
ListNode *build_list(ListNode *l_node, int value){
    
    ListNode *l_node1 = new ListNode();
    l_node1 -> val = value;
    l_node1 -> next = NULL;
    ListNode *curr = l_node;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = l_node1;
    return l_node;
}

int main()
{
    int value;
    cout << "l1 = ";
    cin >> value;
    ListNode *l1_node = new ListNode(value);
    while(getchar()!='\n'){
        cin >> value;
        build_list(l1_node, value);
    }

    cout << "l2 = ";
    cin >> value;
    ListNode *l2_node = new ListNode(value);
    while(getchar()!='\n'){
        cin >> value;
        build_list(l2_node, value);
    }
    /*
    while(l1_node){
        cout << l1_node -> val <<endl;
        l1_node = l1_node -> next;
    }

     while(l2_node){
        cout << l2_node -> val <<endl;
        l2_node = l2_node -> next;
    }
    */
    Solution S;
    ListNode* ans = S.mergeTwoLists(l1_node, l2_node);
    while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}