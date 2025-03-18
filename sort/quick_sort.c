#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void print_array(int arr[], int n);

int main() {
  int arr[] = {5, 3, 4, 1, 2};
  int n = sizeof(arr) / sizeof(int);
  puts("original array: ");
  print_array(arr, n);
  quick_sort(arr, n);
  puts("\nsorted array: ");
  print_array(arr, n);
  return 0;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[low];
  while (low < high) {
    while (low < high && arr[high] > pivot) {
      high--;
    }
    arr[low] = arr[high];
    while (low < high && arr[low] < pivot) {
      low++;
    }
    arr[high] = arr[low];
  }
  arr[low] = pivot;
  return low;
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

void print_array(int arr[], int n) {
  for (uint32_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
