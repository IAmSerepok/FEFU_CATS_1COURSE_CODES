#include <iostream>

using namespace std;

void swap(int arr[], int i, int j){
  int buff = arr[i];
  arr[i] = arr[j];
  arr[j] = buff;
}

int main(){

  int n;

  cin >> n;

  int arr[n+1];

  for (int i = 0; i < n; i++)
    arr[i] = i + 1;

  while (1){

    int j = n - 2;

    while (j >= 0 && arr[j] >= arr[j + 1]) j--;

    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    if(j != -1) cout << endl;

    if (j == -1) break;

    int k = n - 1;

    while (arr[j] >= arr[k]) k--;

    swap(arr, j, k);

    int l = j + 1, r = n - 1;

    while (l<r) swap(arr, l++, r--);
  }
}
