#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (A[j] < x)
        {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int rpartition(int A[], int p, int r)
{
    int i = rand() % (r - p + 1) + p;
    swap(A[r], A[i]);
    return partition(A, p, r);
}

void quicksort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = rpartition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main()
{
    int A[] = {5,4,8,7,6,2,3,4,5,6,8};
    int n = sizeof(A) / sizeof(A[0]);

    quicksort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';
}
