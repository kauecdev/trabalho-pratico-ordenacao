#include "aoh.h"

const int INSERTION_THRESHOLD = 64;

long long insertionSortRange(vector<int> &A, int p, int r)
{

  long long comparisons = 0;

  for (int j = p + 1; j <= r; j++)
  {
    int key = A[j];

    int i = j - 1;

    while (i >= p)
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

long long partitionAoh(vector<int> &A, int p, int r, long long &comparisons)
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

int randomizedPartitionAoh(vector<int> &A, int p, int r, long long &comparisons)
{
  int i = p + rand() % (r - p + 1);

  swap(A[i], A[r]);

  return partitionAoh(A, p, r, comparisons);
}

long long aohImpl(vector<int> &A, int p, int r)
{
  long long comparisons = 0;

  if (p < r)
  {
    int size = r - p + 1;

    if (size <= INSERTION_THRESHOLD)
    {
      comparisons += insertionSortRange(A, p, r);
    }
    else
    {

      long long partComps = 0;

      int q = randomizedPartitionAoh(A, p, r, partComps);

      comparisons += partComps;
      comparisons += aohImpl(A, p, q - 1);
      comparisons += aohImpl(A, q + 1, r);
    }
  }

  return comparisons;
}

long long aoh(vector<int> &A)
{
  return aohImpl(A, 0, A.size() - 1);
}