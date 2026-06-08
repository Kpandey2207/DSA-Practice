class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //using 3 pointers

        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};