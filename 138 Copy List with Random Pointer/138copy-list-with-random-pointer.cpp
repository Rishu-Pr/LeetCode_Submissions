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
    void copyToClone(Node* &cloneHead,Node* &cloneTail, int x){
        Node *temp = new Node(x);
        if(cloneHead==NULL){
            cloneHead = temp;
            cloneTail = temp;
            return;
        }

        cloneTail->next = temp;
        cloneTail = temp;
        return;
    }
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;
        Node* temp = head;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        while(temp){
            copyToClone(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }
        temp = head;
        Node* temp2 = cloneHead;
        while(temp){
            map[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp = head;
        temp2 = cloneHead;
        while(temp2){
            temp2->random = map[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }

        return cloneHead;
    }
};