#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void insertion_sort(int arr[], int n);
void print_array(int arr[], int n);

int main() {
  int arr[] = {5, 3, 4, 1, 2};
  int n = sizeof(arr) / sizeof(int);
  puts("original array: ");
  print_array(arr, n);
  insertion_sort(arr, n);
  puts("\nsorted array: ");
  print_array(arr, n);
  return 0;
}

void insertion_sort(int arr[], int n) {
  for (uint32_t i = 1; i < n; i++) {
    int e = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > e) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = e;
  }
}

void print_array(int arr[], int n) {
  for (uint32_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
