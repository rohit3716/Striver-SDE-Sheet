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
    private:
    int length( ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while( temp ) {
            temp = temp->next;
            size++;
        }
        return size;
    }
public:
    ListNode* solve( ListNode* head, int &k, int n) {
        if( n < k ) return head;

        if( head == NULL )  return NULL;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nnode = NULL;
        int count = 0;

        while( curr != NULL && count < k) {
            nnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nnode;
            count++;
        }

        head->next = solve( nnode, k, n-k);

        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = length(head);
        return solve(head, k , n);
    }
};