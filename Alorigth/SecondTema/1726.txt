#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <cstdint>
using namespace std;

const int64_t maxn = 100000 + 10;

int64_t n;
int64_t arr_x[maxn];
int64_t arr_y[maxn];

void input() {
  cin >> n;
  for (int64_t i = 0; i < n; i++)
    cin >> arr_x[i] >> arr_y[i];
}

int compareMyType(const void *a, const void *b) {
  if (*(int64_t *)a < *(int64_t *)b)
    return -1;
  if (*(int64_t *)a == *(int64_t *)b)
    return 0;
  if (*(int64_t *)a > *(int64_t *)b)
    return 1;
}
void solve() {
  int64_t res = 0;
  qsort(arr_x, n, sizeof(int64_t), compareMyType);
  qsort(arr_y, n, sizeof(int64_t), compareMyType);
  int64_t res1 = 0, res2 = 0;
  for (int64_t i = 1; i < n; i++)
    res1 += (arr_x[i] - arr_x[i - 1]) * i * (n - i);
  // cout << res1 << endl;
  for (int64_t i = 1; i < n; i++)
    res2 += (arr_y[i] - arr_y[i - 1]) * i * (n - i);
  // cout << res2 << endl;
  res = 2 * (res1 + res2) / (n * (n - 1));
  cout << res;
}

int main() {
  input();
  solve();
}