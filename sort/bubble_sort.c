#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

void bubble_sort(int arr[], int n);
void print_array(int arr[], int n);

int main() {
  int arr[] = {5, 3, 4, 1, 2};
  int n = sizeof(arr) / sizeof(int);
  puts("original array: ");
  print_array(arr, n);
  bubble_sort(arr, n);
  puts("\nsorted array: ");
  print_array(arr, n);
  return 0;
}

void bubble_sort(int arr[], int n) {
  for (uint32_t i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (uint32_t j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
    if (swapped == false) {
      return;
    }
  }
}

void print_array(int arr[], int n) {
  for (uint32_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
