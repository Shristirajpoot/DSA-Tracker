#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) 
            return mid; // found
        else if (arr[mid] < target) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1; // not found
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, target);
    if (result != -1) 
        cout << "Element found at index " << result << "\n";
    else 
        cout << "Element not found\n";

    return 0;
}
