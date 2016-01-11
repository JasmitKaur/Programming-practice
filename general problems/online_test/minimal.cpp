#include<iostream>

using namespace std;

void merge_array(int A[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int A[], int l, int r)
{
   if (l < r)
   {
      int m = l+(r-l)/2;
      merge_sort(A, l, m);
      merge_sort(A, m+1, r);
      merge_array(A, l, m, r);
   }
}

int solution(int A[], int N, int B[], int M) {
    int i = 0;
    int j = 0;

    merge_sort(A, 0, N-1);
    merge_sort(B, 0, M-1);

    if ( N == 0 || M == 0 || A[N-1] < B[0] || A[0] > B[M-1])
        return -1;

    while (i<N && j<M) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            return A[i];
        }
    }
    return -1;
}

int main()
{
    int a[5] = { 1, 4, 6, 90, 24 };
    int b[6] = { 2, 3, 5, 7, 10, 11 };
    cout << solution(a, 0, b, 6);

    /*for (int i=0; i<5; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i=0; i<6; i++)
        cout << b[i] << " ";
    cout << endl;*/
    return 0;
}

