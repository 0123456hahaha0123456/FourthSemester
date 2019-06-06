#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
const int maxn = 500 + 10;
typedef pair<int, int> ii;
vector<ii> a[maxn];
int n, m;

int d[maxn];
bool inqueue[500 * 500];

void bellman(int u) {
  int i, v, uv;
  queue<int> qu;

  for (i = 1; i <= n; i++)
    d[i] = 1000111000;
  d[u] = 0;
  qu.push(u);
  inqueue[u] = true;

  while (qu.size()) {
    u = qu.front();
    inqueue[u] = false;
    qu.pop();

    for (i = 0; v = a[u][i].Y; i++) {
      uv = a[u][i].X;
      if (d[v] > d[u] + uv) {
        d[v] = d[u] + uv;
        if (!inqueue[v]) {
          qu.push(v);
          inqueue[v] = true;
        }
      }
    }
  }
}

main() {
  int p, q, w, i, u, v;
  cin >> n >> m;
  while (m--) {
    cin >> p >> q >> w;
    w = 0 - w;
    a[p].push_back(ii(w, q));
  }
  cin >> u >> v;
  for (i = 1; i <= n; i++)
    a[i].push_back(ii(0, 0));
  bellman(u);

  if (d[v] != 1000111000)
    cout << 0 - d[v];
  else
    cout << "No solution";
}