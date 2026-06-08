class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
            return NULL;

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* premid=nullptr;

        while(fast!=NULL && fast->next!=NULL){
            premid=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        premid->next=premid->next->next;

        return head;
    }
};