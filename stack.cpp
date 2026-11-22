#include <chrono>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <class T>
class MyStack
{
private:
    static const int capacity = 10000;
    T data[capacity];
    int top;

public:
    MyStack() : top(-1) {}

    void push(const T &value)
    {
        if (top < capacity - 1)
        {
            data[++top] = value;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            --top;
        }
    }
};

template <class T>
class MyQueue
{
private:
    static const int capacity = 10000;
    T data[capacity];
    int front;
    int size;

public:
    MyQueue() : front(0), size(0) {}

    void enqueue(const T &value)
    {
        if (size < capacity)
        {
            data[(front + size) % capacity] = value;
            ++size;
        }
    }

    void dequeue()
    {
        if (size > 0)
        {
            front = (front + 1) % capacity;
            --size;
        }
    }
};

int main()
{
    const int N = 10000;
    using clock = chrono::steady_clock;

    auto start = clock::now();
    MyStack<int> myStack;
    for (int i = 0; i < N; ++i)
    {
        myStack.push(i);
    }
    for (int i = 0; i < N; ++i)
    {
        myStack.pop();
    }
    auto end = clock::now();
    auto customStackTime = chrono::duration_cast<chrono::microseconds>(end - start);

    start = clock::now();
    stack<int> stlStack;
    for (int i = 0; i < N; ++i)
    {
        stlStack.push(i);
    }
    for (int i = 0; i < N; ++i)
    {
        stlStack.pop();
    }
    end = clock::now();
    auto stlStackTime = chrono::duration_cast<chrono::microseconds>(end - start);

    start = clock::now();
    MyQueue<int> myQueue;
    for (int i = 0; i < N; ++i)
    {
        myQueue.enqueue(i);
    }
    for (int i = 0; i < N; ++i)
    {
        myQueue.dequeue();
    }
    end = clock::now();
    auto customQueueTime = chrono::duration_cast<chrono::microseconds>(end - start);

    start = clock::now();
    queue<int> stlQueue;
    for (int i = 0; i < N; ++i)
    {
        stlQueue.push(i);
    }
    for (int i = 0; i < N; ++i)
    {
        stlQueue.pop();
    }
    end = clock::now();
    auto stlQueueTime = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Custom Stack Time: " << customStackTime.count() << " microseconds" << endl;
    cout << "STL Stack Time: " << stlStackTime.count() << " microseconds" << endl;
    cout << "Custom Queue Time: " << customQueueTime.count() << " microseconds" << endl;
    cout << "STL Queue Time: " << stlQueueTime.count() << " microseconds" << endl;

    return 0;
}