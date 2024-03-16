#include <iostream>
using namespace std;

int sumOfProg(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void merge(int arr[], int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int k = start;

    // Dynamically allocate memory for the temporary array
    int* temp = new int[end - start + 1];

    // Merge two subarrays into the temporary array
    while (i <= middle && j <= end) {
        if (arr[i] >= arr[j]) {
            temp[k - start] = arr[i];
            i++;
        }
        else {
            temp[k - start] = arr[j];
            j++;
        }
        k++;
    }

    // Add remaining elements of the first subarray if any
    while (i <= middle) {
        temp[k - start] = arr[i];
        i++;
        k++;
    }

    // Add remaining elements of the second subarray if any
    while (j <= end) {
        temp[k - start] = arr[j];
        j++;
        k++;
    }

    // Copy the content of the temporary array back into the main array
    for (int p = start; p <= end; p++) {
        arr[p] = temp[p - start];
    }

    // Free the memory allocated for the temporary array
    delete[] temp;
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}



int main() {
    cout << "Merge Sort\n";
    int firstTerm, difference, N;

    cout << "Enter the first element of the array:";
    cin >> firstTerm;

    cout << "Enter the difference: ";
    cin >> difference;

    cout << "Enter the size of the array (100 < N < 1000): ";
    cin >> N;

    // Check for the correctness of the entered data
    if (N <= 100 || N >= 1000) {
        cout << "Invalid array size!" << endl;
        cin >> N;
    }

    int* myarr;
    myarr = new int[N];

    // Fill the array with arithmetic progression members
    for (int i = 0; i < N; ++i) {
        myarr[i] = firstTerm + i * difference;
    }
    cout << "\nInitial array\n";
    for (int i = 0; i < N; i++)
    {
        cout << myarr[i] << " ";
    }

    int summ = sumOfProg(myarr, N);

    mergeSort(myarr, 0, N - 1);

    cout << "\nSorted array in reverse\n";
    for (int i = 0; i < N; i++)
    {
        cout << myarr[i] << " ";
    }

    cout << "\nSum of arithmetic progression\n";
    cout << summ;
    return 0;
}
