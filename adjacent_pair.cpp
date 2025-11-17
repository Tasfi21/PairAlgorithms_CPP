

#include <iostream>
#include <climits>
using namespace std;

struct Result {
    int maxSum;
    int leftIndex;
    int rightIndex;
};

Result findMaxAdjacentPair(int arr[], int low, int high) {
    Result result;

    // Base case: only two elements — only one pair possible
    if (high == low + 1) {
        result.maxSum = arr[low] + arr[high];
        result.leftIndex = low;
        result.rightIndex = high;
        return result;
    }

    int mid = (low + high) / 2;

    // Recurse on left and right halves
    Result left = findMaxAdjacentPair(arr, low, mid);
    Result right = findMaxAdjacentPair(arr, mid, high); // note: not mid+1

    // Check cross pair: last of left half and first of right half
    int crossSum = arr[mid] + arr[mid + 1];

    Result cross;
cross.maxSum = crossSum;
cross.leftIndex = mid;
cross.rightIndex = mid+1;


    // Compare all three
    if (left.maxSum >= right.maxSum && left.maxSum >= cross.maxSum)
        return left;
    else if (right.maxSum >= left.maxSum && right.maxSum >= cross.maxSum)
        return right;
    else
        return cross;
}

int main() {
    int arr[] = {4, 7, 1, 9, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n < 2) {
        cout << "Array must contain at least 2 elements." << endl;
        return 0;
    }

    Result result = findMaxAdjacentPair(arr, 0, n - 1);

    cout << "Max adjacent pair sum: " << result.maxSum << " ("
         << arr[result.leftIndex] << ", " << arr[result.rightIndex] << ")" << endl;

    return 0;
}

