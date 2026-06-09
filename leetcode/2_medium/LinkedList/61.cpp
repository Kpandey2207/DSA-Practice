class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
            return head;
        // Find length
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        k%=n;
        if(k==0)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        // Move fast k steps ahead
        while(k--)
            fast=fast->next;
        // Find kth node from end
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* newHead=slow->next;
        // Break the list
        slow->next=nullptr;
        // Connect tail to old head
        fast->next=head;
        return newHead;
    }
};