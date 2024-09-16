/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
       ListNode* previous = NULL;

       while(node !=NULL && node->next!= NULL){
        node->val = node->next->val;
        previous = node;
        node = node->next;

       } 
       previous->next = NULL;
       delete(node);
    }
};