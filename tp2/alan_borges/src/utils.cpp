#include "utils.h"
#include "queue.h"

void Utils::radix_sort(Planet *arr, int planet_name_char_count, int planet_count){
  int m = 26;
  Queue *queues = new Queue[26];

  for (int i = planet_name_char_count - 1; i >= 0; i--) {
    for (int j = 0; j < planet_count; j++) {
      queues[arr[j].get_name().c_str()[i] - 'a'].add(arr[j]);
    }
    int pos = 0;
    for (int j = 0; j < m; j++) {
      while (queues[j].get_size() > 0) {
        arr[pos] = queues[j].dequeue();
        pos++;
      }
    }
  }
  free(queues);
}

void Utils::merge(Planet arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;

  Planet *left = new Planet[n1];
  Planet *right = new Planet[n2];

  for (i = 0; i < n1; i++) left[i] = arr[l + i];
  for (j = 0; j < n2; j++) right[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (left[i].get_time_spent() <= right[j].get_time_spent()) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void Utils::merge_sort(Planet arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    // Binary division
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);

    // Merges both sides
    merge(arr, l, m, r);
  }
}

void Utils::print(int arr[], int n) {
  for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
}
