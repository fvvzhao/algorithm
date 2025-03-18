#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void heapify(int arr[], int n, uint32_t i);
void heap_sort(int arr[], int n);
void print_array(int arr[], int n);

int main() {
  int arr[] = {5, 3, 4, 1, 2};
  int n = sizeof(arr) / sizeof(int);
  puts("original array: ");
  print_array(arr, n);
  heap_sort(arr, n);
  puts("\nsorted array: ");
  print_array(arr, n);
  return 0;
}

void heapify(int arr[], int n, uint32_t i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  while (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  while (right < n && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    int temp = arr[largest];
    arr[largest] = arr[i];
    arr[i] = temp;
    heapify(arr, n, largest);
  }
}

void heap_sort(int arr[], int n) {
  for (uint32_t i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  for (uint32_t i = n - 1; i > 0; i--) {
    int temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;
    heapify(arr, i, 0);
  }
}

void print_array(int arr[], int n) {
  for (uint32_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
