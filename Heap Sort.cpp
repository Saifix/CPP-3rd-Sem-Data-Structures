#include <iostream> 
using namespace std;
#define MAX 1000

void heapify_insert(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0) {
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapify_insert(arr, n, parent);
        }
    }
}

void insertNode(int arr[], int& n, int Key)
{
    n = n + 1;
    arr[n - 1] = Key; 
    heapify_insert(arr, n, n - 1);
}

void heapify_del(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2 * i + 1;  
    int r = 2 * i + 2;  
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify_del(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_del(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify_del(arr, i, 0);
    }
}

void deleteRoot(int arr[], int& n)
{
    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    heapify_del(arr, n, 0);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = { 10, 5, 3, 2, 4 };
    int n = 5;
    int ns = sizeof(arr) / sizeof(arr[0]);
    int key = 15;
    insertNode(arr, n, key);
    deleteRoot(arr, ns);
    printArray(arr, n);
    heapSort(arr, ns);
    cout << "Sorted array is \n";
    printArray(arr, ns);
    system("pause");
}
