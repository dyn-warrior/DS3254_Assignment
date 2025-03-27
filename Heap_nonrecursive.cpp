//Heap Data Structure with Non-Recursive maxHeapify in C++

#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    // Non-recursive maxHeapify
    void maxHeapify(int index) {
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
    // Insert element into the heap
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        int parent = (index - 1) / 2;

        // Bubble up (Heapify Up)
        while (index > 0 && heap[parent] < heap[index]) {
            std::swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Extract maximum element (Root)
    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty!\n";
            return -1;
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            maxHeapify(0); // Restore heap property

        return maxValue;
    }

    // Print Heap
    void printHeap() {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

// Driver Code
int main() {
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(40);
    maxHeap.insert(50);
    maxHeap.insert(100);
    maxHeap.insert(25);

    std::cout << "Max Heap: ";
    maxHeap.printHeap();

    std::cout << "Extracted Max: " << maxHeap.extractMax() << "\n";
    std::cout << "Heap after Extraction: ";
    maxHeap.printHeap();

    return 0;
}
