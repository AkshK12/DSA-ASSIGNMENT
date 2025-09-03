#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        int next = -1;  // default value if no greater element exists
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                next = arr[j]; // found the next greater
                break;         // stop once found
            }
        }
        cout << next << " ";
    }

    return 0;
}
