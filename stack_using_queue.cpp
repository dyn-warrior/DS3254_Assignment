//1. Queue Using Two Stacks (Enqueue Efficient)

#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> stack1, stack2;

public:
    // Enqueue operation (O(1))
    void enqueue(int value) {
        stack1.push(value);
    }

    // Dequeue operation (O(n))
    void dequeue() {
        if (stack1.empty()) {
            std::cout << "Queue Underflow\n";
            return;
        }
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.pop(); // Remove front element
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    // Get front element
    int front() {
        if (stack1.empty()) {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int frontElement = stack2.top();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return frontElement;
    }

    // Check if queue is empty
    bool isEmpty() {
        return stack1.empty();
    }

    // Print queue elements
    void print() {
        std::stack<int> temp = stack1;
        std::stack<int> revStack;
        while (!temp.empty()) {
            revStack.push(temp.top());
            temp.pop();
        }
        while (!revStack.empty()) {
            std::cout << revStack.top() << " ";
            revStack.pop();
        }
        std::cout << "\n";
    }
};

// Driver Code
int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Queue elements: ";
    q.print();
    std::cout << "Front element: " << q.front() << "\n";
    q.dequeue();
    std::cout << "Queue after dequeue: ";
    q.print();
    return 0;
}
