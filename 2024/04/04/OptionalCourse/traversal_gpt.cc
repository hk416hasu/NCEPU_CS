#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to generate all subarrays using stack
void generateSubarrays(const vector<int>& arr) {
    int n = arr.size();

    // Iterate through each element of the array
    for (int i = 0; i < n; ++i) {
        // Stack to store elements of subarray
        stack<int> st;

        // Iterate through each subarray starting at index i
        for (int j = i; j < n; ++j) {
            // Push elements onto stack
            st.push(arr[j]);

            // Print elements of subarray from stack
            stack<int> tempSt = st;
            while (!tempSt.empty()) {
                cout << tempSt.top() << " ";
                tempSt.pop();
            }
            cout << endl;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    cout << "Subarrays of the array: " << endl;
    generateSubarrays(arr);
    getchar();
    return 0;
}
