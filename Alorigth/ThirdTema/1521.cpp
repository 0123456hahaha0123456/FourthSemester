#include <iostream>

using namespace std;

const int maxn = 100000 + 10;
int n, k_first;
int m;
int arr[2 * maxn];
int F[2 * maxn];
void input() {
  cin >> n >> k_first;
  m = 2 * n;
  for (int i = 1; i <= m; i++)
    arr[i] = 1;
  for (int i = 0; i <= m; i++)
    F[i] = 0;
}

void update_tree(int i, int val) {
  while (i <= m) {
    F[i] = F[i] + val;
    i = i + (i & -i);
  }
}
// tinh sl soldat tu khoang i->j
int calc_sum(int i, int j) {
  int result = 0;
  while (j >= i) {
    if (j - (j & -j) >= i) {
      result += F[j];
      j = j - (j & -j);
    } else {
      result += arr[j];
      j = j - 1;
    }
  }
  return result;
}

// tinh sum 1->i
int calc_sum_left(int i) {
  int result = 0;
  while (i >= 1) {
    result = result + F[i];
    i = i - (i & -i);
  }
  return result;
}
// find next i
int post(int x) {
  if (x > n)
    x -= n;
  while (arr[x] != 1) {
    x++;
    if (x > n)
      x = 1;
  }
  return x;
}

void solve() {
  for (int i = 1; i <= m; i++)
    update_tree(i, arr[i]);
  int count = n;
  int i = 1;
  int k;
  while (count > 1) {
    k = k_first;
    if (count < k) {
      k = k % count;
      if (k == 0)
        k = count;
    }
    int j = i + k - 1;
    int tmp = calc_sum(i, j);
    while (tmp != k) {
      j += k - tmp;
      tmp = calc_sum(i, j);
    }

    j = j % n;
    if (j == 0)
      j = n;

    cout << j << " ";
    arr[j] = 0;
    update_tree(j, -1);
    arr[j + n] = 0;
    update_tree(j + n, -1);
    i = post(j + 1);

    //----------------
    count--;
  }
  for (int i = 1; i <= n; i++)
    if (arr[i] == 1)
      cout << i;
}

int main() {
  input();
  solve();
}