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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* tail=head;
        int elements=0;
        while(tail!=NULL){
            elements++;
            tail=tail->next;
        }
        ListNode* ptr2=head;
        for (int i=0; i<(elements-k); i++){
            ptr2=ptr2->next;
        }
        ListNode* ptr1=head;
        for (int i=1; i<k; i++){
            ptr1=ptr1->next;
        }
        int first=ptr1->val;
        int second=ptr2->val;
        ptr1->val=second;
        ptr2->val=first;
        return head;
    }
};