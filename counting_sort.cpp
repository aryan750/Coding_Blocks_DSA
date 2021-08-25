#include <iostream>
using namespace std;

void countSort(int array[], int size) {
 
  int output[size];
  
  int max = array[0];

  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  int count[max+1];
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main() {
  int n;
  cin>>n;
  int array[n];
  for(int i=0;i<n;i++)
  {
  	cin>>array[i];
  }
  countSort(array, n);
  printArray(array, n);
}