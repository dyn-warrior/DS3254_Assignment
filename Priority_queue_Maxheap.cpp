//Priority Queue Using Heap (MaxHeap) in C++
#include <iostream>
#include <vector>

class PriorityQueue {
private:
    std::vector<int> heap; // Using a vector for heap storage

    // Heapify up for insertion
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent] < heap[index]) {
            std::swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Heapify down for extractMax
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == index) break; // Heap property satisfied

            std::swap(heap[index], heap[largest]);
            index = largest; // Move down
        }
    }

public:
    // Insert an element (enqueue)
    void enqueue(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Extract the maximum element (dequeue)
    int dequeue() {
        if (heap.empty()) {
            std::cerr << "Priority Queue is empty!\n";
            return -1;
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);

        return maxValue;
    }

    // Get the maximum element without removing it (peek)
    int peek() {
        if (heap.empty()) {
            std::cerr << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Check if the priority queue is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Print the priority queue
    void printQueue() {
        for (int val : heap)
            std::cout << val << " ";
        std::cout << "\n";
    }
};

// Driver Code
int main() {
    PriorityQueue pq;
    
    pq.enqueue(10);
    pq.enqueue(20);
    pq.enqueue(15);
    pq.enqueue(40);
    pq.enqueue(50);
    pq.enqueue(100);
    pq.enqueue(25);

    std::cout << "Priority Queue: ";
    pq.printQueue();

    std::cout << "Max Element (Peek): " << pq.peek() << "\n";

    std::cout << "Extracting Max: " << pq.dequeue() << "\n";
    std::cout << "Queue after Dequeue: ";
    pq.printQueue();

    return 0;
}
