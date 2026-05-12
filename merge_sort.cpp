#include "merge_sort.h"

long long merge(vector<int> &A, int p, int q, int r)
{
  int n1 = q - p + 1;

  int n2 = r - q;

  vector<int> L(n1 + 1);

  vector<int> R(n2 + 1);

  for (int i = 0; i < n1; i++)
  {
    L[i] = A[p + i];
  }

  for (int j = 0; j < n2; j++)
  {
    R[j] = A[q + 1 + j];
  }

  L[n1] = INT_MAX;

  R[n2] = INT_MAX;

  int i = 0, j = 0;

  long long comparisons = 0;

  for (int k = p; k <= r; k++)
  {
    comparisons++;

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
  }

  return comparisons;
}

long long mergeSortImpl(vector<int> &A, int p, int r)
{
  long long comparisons = 0;

  if (p < r)
  {
    int q = (p + r) / 2;

    comparisons += mergeSortImpl(A, p, q);
    comparisons += mergeSortImpl(A, q + 1, r);
    comparisons += merge(A, p, q, r);
  }

  return comparisons;
}

long long mergeSort(vector<int> &A)
{
  return mergeSortImpl(A, 0, A.size() - 1);
}