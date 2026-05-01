/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node * funcFlat(Node* head){
        if(!head) return NULL;
        while(head->next && !head->child)
            head = head->next;
        
        Node *second = head->next;

        head->next = head->child;
        if(head->next) head->next->prev = head;
        head->child = NULL;

        Node *first = flatten(head->next);

        if(first && second){
            while(first->next) first = first->next;
            first->next = second;
            second->prev = first;
        }
        while(second && second->next)
            second = second->next;

        return second;
    }
public:
    Node* flatten(Node* head) {
        Node *H = head;
        Node *tail = funcFlat(head);

        return H;
    }
};