#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 60010;
int main() {
  int n;
  int arr[maxn];
  long long sum[maxn];
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  sum[0] = 0;
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i - 1] + arr[i];
  long long res = 0;
  int first = 1, last = 1;

  while (first <= n && last <= n) {
    if (sum[last] - sum[first - 1] >= 0) {
      res = max(res, sum[last] - sum[first - 1]);
      last++;
    } else {
      first++;
      if (last < first)
        last = first;
    }
  }
  cout << res;
  return 0;
}