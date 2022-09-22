// #include <cstdio>
// #include <iostream>
// #include <string>
// using namespace std;

// int N, Q;
// char list[26], c;
// void merge(int left, int rs, int right)
// {
//     char tmp[26];
//     int cur = left, le = rs, L = left, R = right;
//     while (left < le && rs < right) {
//         printf("? %c %c\n", list[left], list[rs]);
//         fflush(stdout);
//         scanf(" %c", &c);
//         if (c == '<') {
//             tmp[cur++] = list[left++];
//         } else {
//             tmp[cur++] = list[rs++];
//         }
//     }
//     while (left < le) {
//         tmp[cur++] = list[left++];
//     }
//     while (rs < right) {
//         tmp[cur++] = list[rs++];
//     }
//     for (int i = L; i < R; i++) {
//         list[i] = tmp[i];
//     }
// }
// void mergeSort(int left, int right)
// {
//     if (left >= right - 1)
//         return;
//     int mid = (left + right) / 2;
//     mergeSort(left, mid);
//     mergeSort(mid, right);
//     merge(left, mid, right);
// }
// int main(void)
// {
//     cin >> N >> Q;
//     for (int i = 0; i < 26; i++) {
//         list[i] = 'A' + i;
//     }
//     mergeSort(0, N);
//     cout << "! ";
//     for (int i = 0; i < N; i++) {
//         cout << list[i];
//     }
//     cout << "\n";

//     return 0;
// }

// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
    int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {

        printf("? %c %c\n",
            leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]);
        fflush(stdout);
        char c;
        scanf(" %c", &c);
        if (c == '<') {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    cout << "! ";
    for (auto i = 0; i < size; i++)
        cout << (char)A[i];
    cout << "\n";
}

// Driver code
int main()
{
    int arr[26];
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        arr[i] = (int)'A' + i;

    mergeSort(arr, 0, N - 1);

    printArray(arr, N);
    return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes