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
    ListNode* partition(ListNode* head, int x) {
        vector<int> left;
        vector<int> right;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val>=x){
             right.push_back(temp->val);
             temp = temp->next;
            }
            else{
                left.push_back(temp->val);
                temp = temp->next;
            }
        }
        temp = head;
        for(int i=0;i<left.size();i++){
            temp->val = left[i];
            temp=temp->next;
        }
    for(int i=0;i<right.size();i++){
            temp->val = right[i];
            temp=temp->next;
        }
        return head;
    }
};