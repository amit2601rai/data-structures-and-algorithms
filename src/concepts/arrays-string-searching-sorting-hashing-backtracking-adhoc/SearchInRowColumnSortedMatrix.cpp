#include <iostream>

using namespace std;

int main() {
  int row, column, key;
  cin >> row >> column >> key;
  int a[row + 1][column + 1];
  for (int i = 1; i <= row; i++)
    for (int j = 1; j <= column; j++) cin >> a[i][j];
  int i = 1, j = column;
  while (j > 0 && i <= row) {
    if (key == a[i][j]) {
      cout << i << " " << j << endl;
      break;
    } else if (key > a[i][j]) {
      i++;
    } else
      j--;
  }
  return 0;
}
