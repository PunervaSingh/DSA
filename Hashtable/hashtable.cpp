#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Node{
    public:
        string key;
        T value;
        Node * next;

        Node(string key, T value) {
            this -> key= key;
            this -> value = value;
            next = NULL;
        }

        ~Node() {
            if(next != NULL) {
                delete next;
            }
        }
};

template<typename T>
class Hasgtable{
    Node<T> **table;
    int cs;
    int ts;

    int hashFn(string key) {
        int idx = 0;
        int power = 1;


        for(auto ch: key) {
            idx = (idx + ch*power) % ts;
            power = (power*29) % ts;
        }
        return idx;
    }

    void rehash() {
        //Save the ptr to the oldTable and we will do insertion in the new table
        Node<T> **oldTable = table;
        int oldTs = ts;

        //Increse the table size
        cs = 0;
        ts = 2*ts + 1;
        table = new Node<T> *[ts];
        //you should make it prime

        for(int i = 0; i < ts; i++) {
            table[i] = NULL;
        }

        //Copy elements from old table to new table
        for(int i = 0; i < oldTs; i++) {
            Node<T> *temp = oldTable[i];
            while(temp != NULL) {
                string key = temp -> key;
                T value = temp -> value;
                //happen in the new table
                insert(key, value);
                temp = temp -> next;
            }

            // destroy the ith linked list
            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }
        delete [] oldTable;
    }

    
};