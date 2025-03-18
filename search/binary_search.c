#include <stdio.h>

int binary_search(int arr[], int n, int target);

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(int);
  int number;
  puts("请输入你想寻找的元素：");
  scanf_s("%d", &number);
  printf("%d对应的下标为%d\n", number, binary_search(arr, n, number));
  return 0;
}

int binary_search(int arr[], int n, int target) {
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      return mid;
    }
    else if (arr[mid] > target) {
      right = mid - 1;
    }
    else {
      left = mid + 1;
    }
  }
  return -1;
}
