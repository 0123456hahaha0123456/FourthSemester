#include <bits/stdc++.h>
/*
 _______
| 1 | 2 |
|___|___|
| 3 | 4 |
 -------
*/

using namespace std;
const int max_edge = 512 + 10;
int x, y;
int n;
int maxn;
int arr[max_edge][max_edge];
int _count;
void input() {
  cin >> n;
  maxn = 1;
  for (int i = 0; i < n; i++)
    maxn *= 2;
  cin >> x >> y;
}
void re_paint(int x_left, int y_left, int x_right, int y_right, int x_pos,
              int y_pos) {
  _count++;
  for (int i = x_left; i <= x_right; i++)
    for (int j = y_left; j <= y_right; j++) {
      if (i == x_pos && j == y_pos)
        continue;
      else
        arr[i][j] = _count;
    }
}

void paint(int x_left, int y_left, int x_right, int y_right, int x_pos,
           int y_pos) {
  if (abs(x_right - x_left) == 1 && abs(y_right - y_left) == 1) {
    re_paint(x_left, y_left, x_right, y_right, x_pos, y_pos);
    return;
  }
  int x_tmp = (x_right + x_left) / 2;
  int y_tmp = (y_right + y_left) / 2;
  if (x_pos <= x_tmp && y_pos <= y_tmp) { // neu x,y o phan 1
    _count++;
    arr[x_tmp][y_tmp + 1] = _count; // 3
    arr[x_tmp + 1][y_tmp] = _count; // 2
    arr[x_tmp + 1][y_tmp + 1] = _count; // 4
    paint(x_left, y_left, x_tmp, y_tmp, x_pos, y_pos); // phan 1
    paint(x_tmp + 1, y_left, x_right, y_tmp, x_tmp + 1, y_tmp); // phan 2
    paint(x_left, y_tmp + 1, x_tmp, y_right, x_tmp, y_tmp + 1); // phan 3
    paint(x_tmp + 1, y_tmp + 1, x_right, y_right, x_tmp + 1,
          y_tmp + 1); // phan 4
  } else if (x_pos > x_tmp && y_pos <= y_tmp) { // x,y phan 2
    _count++;
    arr[x_tmp][y_tmp] = _count; // 1
    arr[x_tmp][y_tmp + 1] = _count; // 3
    arr[x_tmp + 1][y_tmp + 1] = _count; // 4
    paint(x_left, y_left, x_tmp, y_tmp, x_tmp, y_tmp); // phan 1
    paint(x_tmp + 1, y_left, x_right, y_tmp, x_pos, y_pos); // phan 2
    paint(x_left, y_tmp + 1, x_tmp, y_right, x_tmp, y_tmp + 1); // phan 3
    paint(x_tmp + 1, y_tmp + 1, x_right, y_right, x_tmp + 1,
          y_tmp + 1); // phan 4
  } else if (x_pos <= x_tmp && y_pos > y_tmp) { // x,y phan 3
    _count++;
    arr[x_tmp][y_tmp] = _count; // 1
    arr[x_tmp + 1][y_tmp] = _count; // 2
    arr[x_tmp + 1][y_tmp + 1] = _count; // 4
    paint(x_left, y_left, x_tmp, y_tmp, x_tmp, y_tmp); // phan 1
    paint(x_tmp + 1, y_left, x_right, y_tmp, x_tmp + 1, y_tmp); // phan 2
    paint(x_left, y_tmp + 1, x_tmp, y_right, x_pos, y_pos); // phan 3
    paint(x_tmp + 1, y_tmp + 1, x_right, y_right, x_tmp + 1,
          y_tmp + 1); // phan 4
  } else { // x,y phan 4
    _count++;
    arr[x_tmp][y_tmp] = _count; // 1
    arr[x_tmp][y_tmp + 1] = _count; // 3
    arr[x_tmp + 1][y_tmp] = _count; // 2
    paint(x_left, y_left, x_tmp, y_tmp, x_tmp, y_tmp); // phan 1
    paint(x_tmp + 1, y_left, x_right, y_tmp, x_tmp + 1, y_tmp); // phan 2
    paint(x_left, y_tmp + 1, x_tmp, y_right, x_tmp, y_tmp + 1); // phan 3
    paint(x_tmp + 1, y_tmp + 1, x_right, y_right, x_pos, y_pos); // phan 4
  }
}
void solve() {
  memset(arr, -1, max_edge * max_edge);
  arr[x][y] = 0;
  paint(1, 1, maxn, maxn, x, y);
  for (int i = 1; i <= maxn; i++) {
    for (int j = 1; j <= maxn; j++)
      cout << arr[i][j] << ' ';
    cout << '\n';
  }
}
int main() {
  int T = 1;
  while (T > 0) {
    _count = 0;
    input();
    solve();
    T--;
  }
}
