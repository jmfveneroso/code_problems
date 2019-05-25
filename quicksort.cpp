#include <vector>
#include <iostream>

void print_array(std::vector<int>& arr) { 
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i];
    if (i < arr.size() - 1) std::cout << ", ";
  }
  std::cout << std::endl;
}

// This partition function guarantees that the elements
// below the index are smaller than the pivot and the
// elements above the index are larger or equal to the 
// pivot.
void hoare_quicksort(std::vector<int>& arr, int low, int high) {
  if (low >= high) return;

  int pivot = arr[(low + high) / 2];
  int i = low, j = high;

  while (i < j) {
    while (arr[i] < pivot) i++;
    while (arr[j] > pivot) j--;

    if (i < j) {
      arr[j] ^= arr[i];
      arr[i] ^= arr[j];
      arr[j] ^= arr[i];
      i++; j--;
    }
  } 

  int pivot_index = j;
  hoare_quicksort(arr, low, pivot_index);
  hoare_quicksort(arr, pivot_index+1, high);
}

void lomuto_quicksort(std::vector<int>& arr, int low, int high) {
  if (low >= high) return;

  int pivot = arr[high];
  int i = low, j = low;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      int aux = arr[j];
      arr[j] = arr[i];
      arr[i] = aux;
      i += 1;
    }
  }
  int aux = arr[high];
  arr[high] = arr[i];
  arr[i] = aux;

  lomuto_quicksort(arr, low, i-1);
  lomuto_quicksort(arr, i+1, high);
}

int main() {
  std::vector<int> numbers {3, 7, 8, 5, 2, 1, 9, 5, 4};
  std::vector<int> expected {1, 2, 3, 4, 5, 5, 7, 8, 9};

  print_array(numbers);
  lomuto_quicksort(numbers, 0, numbers.size()-1);

  print_array(expected);
  print_array(numbers);

  return 0;
}
