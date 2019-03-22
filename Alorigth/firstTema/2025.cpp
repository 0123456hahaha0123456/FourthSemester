#include <iostream>
#include <cmath>

using namespace std;

long long solve(int n, int k);
int main() {
  int T, n, k;
  cin >> T;
  while (T > 0) {
    cin >> n >> k;
    cout << solve(n, k) << "\n";
    T--;
  }
}

long long solve(int n, int k) {
  int arr[10010];
  for (int i = 0; i < k; i++) {
    arr[i] = n / k;
  }
  for (int i = 0; i < n % k; i++)
    arr[i]++;
  long long res = 0;
  for (int i = 0; i < k; i++)
    for (int j = i + 1; j < k; j++)
      res += arr[i] * arr[j];
  return res;
}