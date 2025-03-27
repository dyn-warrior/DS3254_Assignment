//Stack Using Two Queues (Push Efficient)

#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> queue1, queue2;

public:
    // Push operation (O(1))
    void push(int value) {
        queue1.push(value);
    }

    // Pop operation (O(n))
    void pop() {
        if (queue1.empty()) {
            std::cout << "Stack Underflow\n";
            return;
        }
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        queue1.pop(); // Remove top element
        std::swap(queue1, queue2);
    }

    // Get top element
    int top() {
        if (queue1.empty()) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int topElement = queue1.front();
        queue2.push(queue1.front());
        queue1.pop();
        std::swap(queue1, queue2);
        return topElement;
    }

    // Check if stack is empty
    bool isEmpty() {
        return queue1.empty();
    }

    // Print stack elements
    void print() {
        std::queue<int> temp = queue1;
        std::queue<int> revQueue;
        while (!temp.empty()) {
            revQueue.push(temp.front());
            temp.pop();
        }
        while (!revQueue.empty()) {
            std::cout << revQueue.front() << " ";
            revQueue.pop();
        }
        std::cout << "\n";
    }
};

// Driver Code
int main() {
    StackUsingQueues s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "Stack elements: ";
    s.print();
    std::cout << "Top element: " << s.top() << "\n";
    s.pop();
    std::cout << "Stack after pop: ";
    s.print();
    return 0;
}
