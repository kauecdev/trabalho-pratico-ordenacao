#include "heap_sort.h"

int left(int i)
{
  return 2 * i + 1;
}

int right(int i)
{
  return 2 * i + 2;
}

long long maxHeapify(vector<int> &A, int i, int heapSize)
{
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest = i;

  long long comps = 0;

  if (l < heapSize)
  {
    comps++;
    if (A[l] > A[largest])
    {
      largest = l;
    }
  }

  if (r < heapSize)
  {
    comps++;
    if (A[r] > A[largest])
    {
      largest = r;
    }
  }

  if (largest != i)
  {
    swap(A[i], A[largest]);
    comps += maxHeapify(A, largest, heapSize);
  }

  return comps;
}

long long buildMaxHeap(vector<int> &A, int &heapSize)
{
  heapSize = A.size();
  long long comps = 0;

  for (int i = (A.size() / 2) - 1; i >= 0; i--)
  {
    comps += maxHeapify(A, i, heapSize);
  }

  return comps;
}

long long heapSort(vector<int> &A)
{
  int heapSize;
  long long comps = buildMaxHeap(A, heapSize);

  for (int i = A.size() - 1; i >= 1; i--)
  {
    swap(A[0], A[i]);
    heapSize--;
    comps += maxHeapify(A, 0, heapSize);
  }

  return comps;
}