// What arae heaps? - Binary tree with at most 2 children. It is complete binary tree(CBT)
// CBT - All levels should be completely filled except last level, but it must be filled in Left to right order.
// Heap Order property
// Max heap -- parent >= children
// Min heap -- parent <= children

// ------------ TIME COMPLEXITY ------------//
// 1) INSERT - O(Log N)
// 2) Pop Max/ Pop Min - O(Log N)
// 3) Get Max/ Get Min - O(1)

#include<iostream>
#include<vector>
using namespace std;

class Heap {
    vector<int> v;

    void heapify(int i) {
        int left = 2*i;
        int right = 2*i + 1;

        int minIdx = i;
        if(left < v.size() && v[left] < v[i]) {
            minIdx = left;
        }
        if(right < v.size() && v[right] < v[minIdx]) {
            minIdx = right;
        }
        if(minIdx != i) {
            swap(v[i], v[minIdx]);
            heapify(minIdx);
        }
    }

    public:
        Heap(int default_size = 10) {
            v.reserve(default_size + 1);
            v.push_back(-1);
        };

        void push(int data) {
            // add data to end of the heap
            v.push_back(data);

            int idx = v.size() - 1;
            int parent = idx / 2;

            while(idx > 1 && v[idx] < v[parent]) {
                swap(v[idx], v[parent]);
                idx = parent;
                parent = parent / 2;
            }
        }

        // Return Min element
        int top() {
            return v[1];
        }

        // Remove min element
        void pop() {
            // 1. Swap first and last element
            int idx = v.size() - 1;
            swap(v[1], v[idx]);
            v.pop_back();
            heapify(1);
        }

        bool empty() {
            return v.size() == 1;
        }
};