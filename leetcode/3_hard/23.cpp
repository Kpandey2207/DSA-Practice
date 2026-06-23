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
    ListNode* convert(vector<int>& merged){
        if(merged.empty())
            return NULL;
        ListNode* newHead=new ListNode(merged[0]);
        ListNode* tail=newHead;
        for(int i=1;i<merged.size();i++){
            ListNode* node=new ListNode(merged[i]);
            tail->next=node;
            tail=tail->next;
        }
        return newHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> merged;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                merged.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(merged.begin(),merged.end());
        return convert(merged);
    }
};