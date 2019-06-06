#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int dd[maxn][maxn];
int colour[maxn];
int n;
bool ok;

void DFS(int x) {
  for (int i = 1; i <= n; i++)
    if (dd[i][x] == 1 || dd[x][i] == 1) {
      if (colour[i] == -1) {
        colour[i] = 1 - colour[x];
        DFS(i);
      } else if (colour[x] == colour[i])
        ok = false;
    }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dd[i][j] = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    while (x != 0) {
      dd[i][x] = 1;
      dd[x][i] = 1;
      cin >> x;
    }
  }
  ok = true;
  for (int i = 1; i <= n; i++)
    colour[i] = -1;
  for (int i = 1; i <= n; i++) {
    if (colour[i] == -1) {
      colour[i] = 0;
      DFS(i);
    }
  }
  if (ok) {
    for (int i = 1; i <= n; i++)
      cout << colour[i];
  } else
    cout << -1;
}