class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Safe check: list khali ho, 1 element ho, ya rotation 0 ho
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Step 1: List ka size (length) nikalyein aur tail node khojein
        ListNode* tail = head;
        int size = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            size++;
        }

        // Step 2: k ko optimize karein (agar k bada ho)
        k = k % size;
        if (k == 0) return head; // Agar rotation ki zaroorat hi nahi hai

        // Step 3: Naye tail tak pahunchein (Aage se Size - k kadam)
        ListNode* temp = head;
        for (int i = 1; i < (size - k); i++) {
            temp = temp->next;
        }

        // Step 4: Links ko aapas mein badlein
        ListNode* newHead = temp->next; // Naya head mil gaya
        temp->next = nullptr;           // Puraani list ka end break kiya
        tail->next = head;              // Puraane tail ko purane head se joda

        return newHead;
    }
};
