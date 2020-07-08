#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char *a, const char *b) {
  int out = 0;
  while (*(a++) != '\0' && *(b++) != '\0') {
    if (*a > *b) {
      out = 1;
      break;
    }
    if (*a < *b) {
      out = -1;
      break;
    }
  }

  if (*a == '\0')
    out = -1;
  if (*b == '\0')
    out = 1;
  return out;
}

int lexicographic_sort_reverse(const char *a, const char *b) {
  int out = 0;
  while (*(a++) != '\0' && *(b++) != '\0') {
    if (*a > *b) {
      out = -1;
      break;
    }
    if (*a < *b) {
      out = 1;
      break;
    }
  }

  if (*a == '\0')
    out = -1;
  if (*b == '\0')
    out = 1;
  return out;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b) {
  int out = 0;
  while (*(a++) != '\0' && *(b++) != '\0') {
    if (*a > *b) {
      out = 1;
      break;
    }
    if (*a < *b) {
      out = -1;
      break;
    }
  }

  if (*a == '\0')
    out = -1;
  if (*b == '\0')
    out = 1;
  return out;
}

int sort_by_length(const char *a, const char *b) {
  int out = 0;
  while (*(a++) != '\0' && *(b++) != '\0')
    ;

  if (*a == '\0')
    out = -1;
  if (*b == '\0')
    out = 1;
  return out;
}

void swap(char **arr, int l, int r) {
  char *temp = arr[l];
  arr[l] = arr[r];
  arr[r] = temp;
  return;
}

int partition(char **arr, int left, int right, char *pivot,
              int (*cmp_func)(const char *a, const char *b)) {
  // printf("partition\n");
  while (left <= right) {
    while (cmp_func(pivot, arr[left]) < 0) {
      left++;
    }
    while (cmp_func(arr[right], pivot) < 0) {
      right--;
    }
    if (left <= right) {
      swap(arr, left, right);
      left++;
      right--;
    }
  }
  return left;
}

void quick_sort(char **arr, int left, int right,
                int (*cmp_func)(const char *a, const char *b)) {

  if (left >= right)
    return;

  // printf("quick_sortn\n");
  char *pivot = arr[(left + right) / 2];
  int index = partition(arr, left, right, pivot, cmp_func);
  quick_sort(arr, left, index - 1, cmp_func);
  quick_sort(arr, index, right, cmp_func);
  return;
}

void string_sort(char **arr, const int len,
                 int (*cmp_func)(const char *a, const char *b)) {
  quick_sort(arr, 0, len - 1, cmp_func);
  return;
}

int main() {
  int n;
  scanf("%d", &n);

  char **arr;
  arr = (char **)malloc(n * sizeof(char *));

  for (int i = 0; i < n; i++) {
    *(arr + i) = malloc(1024 * sizeof(char));
    scanf("%s", *(arr + i));
    *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
  }

  string_sort(arr, n, lexicographic_sort);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, lexicographic_sort_reverse);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_length);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_number_of_distinct_characters);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");
}
