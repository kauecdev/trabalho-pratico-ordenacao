#include "quick_sort.h"

long long partition(vector<int> &A, int p, int r, long long &comparisons)
{
  int x = A[r];
  int i = p - 1;

  for (int j = p; j < r; j++)
  {
    comparisons++;

    if (A[j] <= x)
    {
      i++;
      swap(A[i], A[j]);
    }
  }

  swap(A[i + 1], A[r]);

  return i + 1;
}

long long randomizedPartition(vector<int> &A, int p, int r, long long &comparisons)
{
  int i = p + rand() % (r - p + 1);

  swap(A[i], A[r]);

  int x = A[r];

  int idx = p - 1;

  for (int j = p; j < r; j++)
  {
    comparisons++;

    if (A[j] <= x)
    {
      idx++;

      swap(A[idx], A[j]);
    }
  }

  swap(A[idx + 1], A[r]);

  return idx + 1;
}

long long quickSortImpl(vector<int> &A, int p, int r)
{
  long long comparisons = 0;

  if (p < r)
  {
    long long partComps = 0;
    int q = randomizedPartition(A, p, r, partComps);

    comparisons += partComps;
    comparisons += quickSortImpl(A, p, q - 1);
    comparisons += quickSortImpl(A, q + 1, r);
  }

  return comparisons;
}

long long quickSort(vector<int> &A)
{
  return quickSortImpl(A, 0, A.size() - 1);
}
