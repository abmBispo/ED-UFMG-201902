#ifndef __UTILS___
#define __UTILS__
#include <iostream>
#include "planet.h"

class Utils {
private:
  static int get_max(int arr[], int n);
  static void count_sort(int arr[], int n, int exp);
  static void merge(Planet arr[], int l, int m, int r);

public:
  static void merge_sort(Planet arr[], int l, int r);
  static void radix_sort(Planet *arr, int planet_name_char_count, int planet_count);
  static void print(int arr[], int n);
};
#endif
