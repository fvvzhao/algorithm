#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void selection_sort(int arr[], int n);
void print_array(int arr[], int n);

int main() {
  int arr[] = {5, 3, 4, 1, 2};
  int n = sizeof(arr) / sizeof(int);
  puts("original array: ");
  print_array(arr, n);
  selection_sort(arr, n);
  puts("\nsorted array: ");
  print_array(arr, n);
  return 0;
}

void selection_sort(int arr[], int n) {
  for (uint32_t i = 0; i < n - 1; i++) {
    uint32_t min = i;
    for (uint32_t j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
}

void print_array(int arr[], int n) {
  for (uint32_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
