class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //using 3 pointers

        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};