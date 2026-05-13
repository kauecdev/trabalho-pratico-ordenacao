#include "bubble_sort.h"

long long bubbleSort(vector<int> &A)
{
  int n = A.size();
  long long comparisons = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = n - 1; j >= i + 1; j--)
    {
      comparisons++;
      if (A[j] < A[j - 1])
      {
        swap(A[j], A[j - 1]);
      }
    }
  }
  return comparisons;
}