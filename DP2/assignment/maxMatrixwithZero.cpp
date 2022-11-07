#include<climits>
int findMaxSquareWithAllZeros(int **arr, int n, int m) {

  if(n == 0 && m == 0)
	return 0;
  int **ans = new int *[n];

  for (int i = 0; i < n; i++) {
    ans[i] = new int[m];
    for (int j = 0; j < m; j++)
      ans[i][j] = -1;
  }

  // set 0th row
  for (int j = 0; j < m; j++) {

    if (arr[0][j] == 0)
      ans[0][j] = 1;

    else
      ans[0][j] = 0;
  }

  // set 0th column
  for (int i = 1; i < n; i++) {

    if (arr[i][0] == 0)
      ans[i][0] = 1;

    else
      ans[i][0] = 0;
  }

  // set remaining elements of matrix
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {

      if (arr[i][j] == 1)
        ans[i][j] = 0;

      else {
        if (arr[i][j] == 0) {
          ans[i][j] =
              min(ans[i - 1][j - 1], min(ans[i - 1][j], ans[i][j - 1])) + 1;
        }
      }
    }
  }

  // return max from ans;
  int maxValue = INT_MIN;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maxValue < ans[i][j])
        maxValue = ans[i][j];
    }
  }

  return maxValue;
}