#include "insertion_sort.h"

long long insertionSort(vector<int> &A)
{
  long long comparisons = 0;
  int n = A.size();

  for (int j = 1; j < n; j++)
  {
    int key = A[j];
    int i = j - 1;

    while (i >= 0)
    {
      comparisons++;
      if (A[i] > key)
      {
        A[i + 1] = A[i];
        i--;
      }
      else
      {
        break;
      }
    }

    A[i + 1] = key;
  }

  return comparisons;
}