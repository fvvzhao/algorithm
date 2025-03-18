#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);
void print_array(int arr[], int n);

int main() {
  int arr[] = {5, 3, 4, 1, 2};
  int n = sizeof(arr) / sizeof(int);
  puts("original array: ");
  print_array(arr, n);
  merge_sort(arr, 0, n - 1);
  puts("\nsorted array: ");
  print_array(arr, n);
  return 0;
}

void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int arr1[n1];
  int arr2[n2];
  for (uint32_t i = 0; i < n1; i++) {
    arr1[i] = arr[left + i];
  }
  for (uint32_t i = 0; i < n2; i++) {
    arr2[i] = arr[mid + 1 + i];
  }

  uint32_t i = 0;
  uint32_t j = 0;
  uint32_t k = left;
  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j]) {
      arr[k] = arr1[i];
      i++;
      k++;
    }
    else {
      arr[k] = arr2[j];
      j++;
      k++;
    }
  }
  while (i < n1) {
    arr[k] = arr1[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = arr2[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

void print_array(int arr[], int n) {
  for (uint32_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
