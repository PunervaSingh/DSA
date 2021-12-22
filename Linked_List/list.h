// Linked List is a sequence or order. Memory is created dynamically on the fly.
// TTR - Improper handling can lead to segmentation faults.
#include<stdio.h>

class Node {
    int data;

    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }

    public:
        Node * next;
        Node(int d){ 
            data = d;
            next = NULL;
        }
        friend class List;
        int getData() { return data; }
};

class List {
    Node * head;
    Node * tail;

    int helper(Node * start, int key) {
        // base case
        if(start == NULL) {
            return -1;
        }
        // value matches
        if(start -> data == key) {
            return 0;
        }
        // remaining part of the linked list
        int subIdx = helper(start->next, key);
        if(subIdx == -1) {
            return -1;
        }
        return subIdx + 1;
    }

    public:
        List(){
            head = NULL;
            tail = NULL;
        }

        void push_front(int data) {
            Node * n = new Node(data);
            if(head == NULL) {
                head = tail = n;
            }
            else{
                // Node * n = new Node(data);
                n -> next = head;
                head = n;
            }
        }

        void push_back(int data) {
            Node * n = new Node(data);
            if(head == NULL) {
                head = tail = n;
            }
            else{
                // Node * n = new Node(data);
                tail -> next = n;
                tail = n;
            }
        }

        void insert(int data, int pos) {
            if(pos == 0) {
                push_front(data);
                return;
            }

            // Otherwise
            Node * temp = head;
            for(int jump = 1; jump <= pos - 1; jump++) {
                temp = temp -> next;
            }
            Node * n = new Node(data);
            n -> next = temp -> next;
            temp -> next = n;
        }

        // Search Operation
        // Linear Search
        bool search(Node * head, int key) {
            Node * temp = head;
            while(temp != NULL) {
                if(temp -> data == key) {
                    return true;
                }
                temp = temp -> next;
            }
            return false;
        }

        // ---------- OR ------------- //
        int search_index(int key) {
            Node * temp = head;
            int idx = 0;
            while(temp != NULL) {
                if(temp -> data == key) {
                    return idx;
                }
                idx++;
                temp = temp -> next;
            }
            return -1;
        }

        // -------- RECURSIVELY ---------- //
        bool search_recursive(Node * head, int key) {
            if(head == NULL) {
                return false;
            }
            // rec case check at head, remaining linked list
            if(head -> data == key) {
                return true;
            }
            else{
                return search_recursive(head->next, key);
            }
        }

        // --------- recursive index --------- //
        int recursive_search(int key) {
            int idx = helper(head, key);
            return idx;
        }

        void pop_front() {
            Node * temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
        }

        // ----------- REVERSE LL ------------- //
        void reverse(Node *& head) {
            Node * c = head;
            Node * p = NULL;
            Node * n;

            while(c != NULL) {
                // Save the next node
                n = c -> next;

                // make the current node point to previous
                c -> next = p;

                // Update p and c take them 1 step forward
                p = c;
                c = n;
            }
            head = p;
        }

        Node * get_head() {
            return head;
        }

        // Distructor of list class
        ~List() {
            if(head != NULL) {
                delete head;
            }
        }
};