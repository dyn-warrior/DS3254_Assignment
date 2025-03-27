//Heap Sort Using Heap Data Structure in C++

#include <iostream>
#include <vector>

class HeapSort {
private:
    std::vector<int> heap;

    // Heapify function to maintain max heap property
    void maxHeapify(int index, int heapSize) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < heapSize && heap[left] > heap[largest])
                largest = left;
            if (right < heapSize && heap[right] > heap[largest])
                largest = right;

            if (largest == index) break; // If heap property is satisfied, stop

            std::swap(heap[index], heap[largest]);
            index = largest; // Move downward
        }
    }

    // Build Max Heap
    void buildMaxHeap() {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(i, n);
    }

public:
    HeapSort(const std::vector<int>& arr) : heap(arr) {}

    // Perform Heap Sort
    void sort() {
        int n = heap.size();
        buildMaxHeap();

        // Extract elements one by one
        for (int i = n - 1; i > 0; i--) {
            std::swap(heap[0], heap[i]);  // Move max element to the end
            maxHeapify(0, i); // Restore heap property on reduced heap
        }
    }

    // Print sorted array
    void printArray() {
        for (int val : heap)
            std::cout << val << " ";
        std::cout << "\n";
    }
};

// Driver Code
int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";

    HeapSort hs(arr);
    hs.sort();

    std::cout << "Sorted array using Heap Sort: ";
    hs.printArray();

    return 0;
}
