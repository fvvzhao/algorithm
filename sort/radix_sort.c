#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

void counting_sort(int arr[], int n, int exp);
void radix_sort(int arr[], int n);
void print_array(int arr[], int n);

int main() {
  int arr[] = {5, 3, 4, 1, 2};
  int n = sizeof(arr) / sizeof(int);
  puts("original array: ");
  print_array(arr, n);
  radix_sort(arr, n);
  puts("\nsorted array: ");
  print_array(arr, n);
  return 0;
}

void counting_sort(int arr[], int n, int exp) {
  int max = arr[0];
  for (uint32_t i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  int* count = (int*)malloc(sizeof(int) * (max + 1));
  for (uint32_t i = 0; i < max + 1; i++) {
    count[i] = 0;
  }

  // 在count数组中统计每个元素的个数
  for (uint32_t i = 0; i < n; i++) {
    int digit = (arr[i] / exp) % 10;
    count[digit]++;
  }

  // 计算前缀和
  for (uint32_t i = 1; i < max + 1; i++) {
    count[i] += count[i - 1];
  }

  int* result = (int*)malloc(sizeof(int) * n);
  for (int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    result[count[digit] - 1] = arr[i];
    count[digit]--;
  }

  for (uint32_t i = 0; i < n; i++) {
    arr[i] = result[i];
  }

  free(count);
  free(result);
}

void radix_sort(int arr[], int n) {
  int max = arr[0];
  for (uint32_t i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  for (int exp = 1; (max / exp) > 0; exp *= 10) {
    counting_sort(arr, n, exp);
  }
}

void print_array(int arr[], int n) {
  for (uint32_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
