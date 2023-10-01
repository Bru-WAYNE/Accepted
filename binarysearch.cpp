#include <iostream>

using namespace std;

int binary_search(int *array, int size, int element) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (array[mid] == element) {
      return mid;
    } else if (array[mid] < element) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  int array[] = {1, 5, 3, 2, 4};
  int size = sizeof(array) / sizeof(array[0]);

  int element = 3;

  int index = binary_search(array, size, element);

  if (index != -1) {
    cout << "The element " << element << " is present at index " << index << endl;
  } else {
    cout << "The element " << element << " is not present in the array" << endl;
  }

  return 0;
}
