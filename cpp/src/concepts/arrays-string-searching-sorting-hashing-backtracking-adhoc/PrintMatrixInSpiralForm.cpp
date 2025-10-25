#include <iostream>

using namespace std;

int main() {
  int row, col;
  cin >> row >> col;
  int matrix[row][col];
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) cin >> matrix[i][j];

  /** Spiral Printing **/
  int s_row = 0;
  int e_row = row - 1;
  int s_col = 0;
  int e_col = col - 1;

  while (s_row <= e_row && s_col <= e_col) {
    for (int i = s_col; i <= e_col; i++) {
      cout << matrix[s_row][i] << " ";
    }
    s_row++;

    for (int i = s_row; i <= e_row; i++) {
      cout << matrix[i][e_col] << " ";
    }
    e_col--;
    for (int i = e_col; i >= s_col; i--) {
      cout << matrix[e_row][i] << " ";
    }
    e_row--;
    for (int i = e_row; i >= s_row; i--) {
      cout << matrix[i][s_col] << " ";
    }
    s_col++;
  }
  cout << endl;
  return 0;
}
