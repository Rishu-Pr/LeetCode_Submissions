class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int x)
    {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class MyLinkedList
{
    Node *head;
    Node *tail;
    int size;

public:
    MyLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get(int index)
    {
        if (head == NULL || index > (size - 1) || index < 0)
            return -1;
        Node *ittr = head;
        for (int i = 0; i < index; i++)
        {
            ittr = ittr->next;
        }
        return ittr->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == size)
        {
            addAtTail(val);
        }
        else if (index < size && index > 0)
        {
            Node *ittr = head;
            Node *newNode = new Node(val);
            for (int i = 0; i < index - 1; i++)
            {
                ittr = ittr->next;
            }
            (ittr->next)->prev = newNode;
            newNode->next = ittr->next;
            ittr->next = newNode;
            newNode->prev = ittr;
            size++;
        }
        return;
    }

    void deleteAtIndex(int index)
{
    if (index >= 0 && index < size)
    {
        Node *ittr = head;
        if (index == 0)
        {
            ittr = head;
            head = head->next;
            if (head != NULL) head->prev = NULL;
            else tail = NULL; // list became empty
        }
        else if (index == size - 1)
        {
            ittr = tail;
            tail = tail->prev;
            if (tail != NULL) tail->next = NULL;
            else head = NULL; // list became empty
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                ittr = ittr->next;
            }
            ittr->prev->next = ittr->next;
            ittr->next->prev = ittr->prev;
        }
        delete ittr;
        size--;
    }
}

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */