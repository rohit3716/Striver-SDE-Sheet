/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Step 1: make copy of all nodes and insert in betwenn

        Node* temp = head;

        while( temp != NULL ) {
            Node* nn = new Node(temp->val);
            nn->next = temp->next;
            temp->next = nn;
            temp = temp->next->next;
        }

        //step 2: point random pointer of deep copied lists 

        Node* it = head;

        while( it != NULL ) {
            if( it->random != NULL ) {
                it->next->random = it->random->next;
            }
            it = it->next->next;
        }

        //Step 3: Link next ptr of deep copied lists and original lists

        Node* dummy = new Node(0);
        it = head;

        temp = dummy;
        Node* fast;

        while( it != NULL) {
            fast = it->next->next;
            temp->next = it->next;
            it->next = fast;
            temp = temp->next;
            it = fast;
        }
        return dummy->next;
    }
};