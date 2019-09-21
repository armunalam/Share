#include <iostream>

using namespace std;

void merge(int *, int, int, int);
void merge_sort(int *, int, int);

// read input array and call mergesort
int main()
{
    int num;
    cout << "Enter number of elements to be sorted: ";
    cin >> num;
    int *myarray =  new int[num];
    cout << "Enter " << num << " elements to be sorted:" << endl;
    for (int i = 0; i < num; i++)
    {
    	cin >> myarray[i];
    }
    merge_sort(myarray, 0, num - 1);
    cout << "\nSorted array:\n";
    for (int i = 0; i < num - 1; i++)
    {
        cout << myarray[i] << ", ";
    }
    cout << myarray[num - 1] << endl;

    return 0;
}

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        //merge or conquer sorted arrays
        merge(arr, low, high, mid);
    }
}

// Merge sort
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}
