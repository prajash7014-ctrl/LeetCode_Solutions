class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != nullptr) {
            ListNode* next = curr->next;

            // Local maxima or local minima
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                critical.push_back(index);
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Less than 2 critical points
        if (critical.size() < 2) {
            return {-1, -1};
        }

        int minDistance = INT_MAX;

        for (int i = 1; i < critical.size(); i++) {
            minDistance = min(minDistance, critical[i] - critical[i - 1]);
        }

        int maxDistance = critical.back() - critical.front();

        return {minDistance, maxDistance};
    }
};