class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       int size = lists.size();
        vector<int> result;
        for(int i=0;i<size;i++){
        ListNode* temp = lists[i]; 
        while (temp != nullptr) {
            result.push_back(temp->val);
            temp = temp->next;
                }
        }
        sort(result.begin(), result.end());
        ListNode dummy(0); 
        ListNode* tail = &dummy; 
        
        for(int i = 0; i < result.size(); i++){
            tail->next = new ListNode(result[i]); 
            tail = tail->next; 
        }
        
        return dummy.next; 
    }
};