/*
 * File: queue_reversal.cpp
 * Author: Shristi Rajpoot
 * Description: Solution to reverse a queue using recursion.
 * Topic: Queues
 * DSA-Tracker Repository
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Function to reverse a queue using recursion.
 * @param q Reference to the queue to be reversed
 */
void reverseQueue(queue<int> &q) {
    if (q.empty()) return;  // Base case: empty queue

    int frontElement = q.front(); // Store the front element
    q.pop();                     // Remove the front element

    reverseQueue(q);             // Recursively reverse the remaining queue

    q.push(frontElement);        // Push the front element at the back
}

/**
 * Helper function to print elements of the queue.
 * @param q Copy of the queue to print
 */
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, x;

    cout << "Enter number of elements in queue: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    cout << "Original Queue: ";
    printQueue(q);

    reverseQueue(q);

    cout << "Reversed Queue: ";
    printQueue(q);

    return 0;
}
