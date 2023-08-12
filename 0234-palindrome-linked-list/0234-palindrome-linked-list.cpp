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
    ListNode* reverse( ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nn = NULL;

        while( curr != NULL ) {
            nn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nn;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if( head == NULL || head->next == NULL ) {
            return true;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while( fast->next != NULL && fast->next->next != NULL ) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse( slow->next );
        slow = slow->next;

        ListNode* temp = head;

        while( slow != NULL ) {
            if( temp->val != slow->val ) return false;

            slow = slow->next;
            temp = temp->next;
        }
        return true;

    }
};