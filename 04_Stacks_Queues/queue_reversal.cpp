#include <bits/stdc++.h>
using namespace std;

// Function to reverse a queue
void reverseQueue(queue<int> &q) {
    if (q.empty()) return;

    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}

int main() {
    // Example usage:
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    cout << "Original queue: ";
    {
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }

    reverseQueue(q);

    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}
