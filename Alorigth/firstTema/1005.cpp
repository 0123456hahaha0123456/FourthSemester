#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

const int maxn = 25;
int arr[maxn];
int _free[maxn];
int n;
int res = INT_MAX;
long double solve(int n, int k);

void solve() {
  int res_sum_1 = 0;
  int res_sum_2 = 0;
  for (int i = 0; i < n; i++)
    if (_free[i] == 0)
      res_sum_1 += arr[i];
    else
      res_sum_2 += arr[i];
  res = min(res, abs(res_sum_2 - res_sum_1));
}

void _try(int index) {
  if (index == n) {
    solve();
    return;
  }
  for (int j = 0; j < 2; j++) {
    _free[index] = j;
    _try(index + 1);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  _try(0);
  cout << res;
}
