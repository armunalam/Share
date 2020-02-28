def partition(A, p, r):
    x = A[r]
    i = p - 1
    
    for j in range(p, r):
        if A[j] <= x:
            i = i + 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]

    return i + 1

def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q - 1)
        quicksort(A, q + 1, r)

a = [3,7,9,6,11,3,2,5]

quicksort(a, 0, len(a) - 1)

for i in range(len(a)):
    print(a[i])
