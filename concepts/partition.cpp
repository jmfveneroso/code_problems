#include <iostream>
#include <vector>

using namespace std;

void partition(vector<int>& arr) {
  if (!arr.size()) return;

  int gap = 0, pivot = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < pivot) {
      arr[gap++] = arr[i];
      arr[i] = arr[gap];
    }
  }
  arr[gap] = pivot;
}

ostream& operator<<(ostream& os, vector<int>& arr) {
  for (auto& el : arr) cout << el << " ";
  return os;
}

int main() { 
  vector<int> arr { 6, 5, 2, 10, 11, 3, 15 };
  partition(arr);
  cout << arr << "should be:" << endl;
  cout << "< < < 6 >  >  >" << endl << endl;

  vector<int> arr2 { 7, 12, 5, 2, 8, 1, 1, 10, 9, 7, 3 };
  partition(arr2);
  cout << arr2 << "should be:" << endl;
  cout << "< < < < < 7 > >  > > >" << endl << endl;

  vector<int> arr3 { 2, 3 };
  partition(arr3);
  cout << arr3 << "should be 2 3" << endl << endl;

  vector<int> arr4 { 3, 2 };
  partition(arr4);
  cout << arr4 << "should be 2 3" << endl << endl;

  vector<int> arr5 { 5 };
  partition(arr5);
  cout << arr5 << "should be 5" << endl;
  return 0;
}
