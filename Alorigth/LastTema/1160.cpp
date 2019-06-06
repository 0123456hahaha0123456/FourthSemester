#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000 + 10;
const int maxm = 15000 + 10;
int n, m;
int par[maxn];
bool dd[maxm];
struct edge {
  int u, v, ts;
};
vector<edge> cable;

int anc(int p) {
  if (par[p] == p)
    return p;
  else
    return par[p] = anc(par[p]);
}

void join(int u, int v) { par[anc(u)] = anc(v); }

int myComp(edge tmp, edge _tmp) { return tmp.ts < _tmp.ts; }

void kruskal() {
  int res = 0;
  int count = 0;
  int maxTS = 0;
  sort(cable.begin(), cable.end(), myComp);
  for (int i = 0; i <= m; i++)
    dd[i] = false;
  for (int i = 1; i <= n; i++)
    par[i] = i;
  int h = 0;
  for (auto cab : cable) {
    if (anc(cab.u) != anc(cab.v)) {
      join(cab.u, cab.v);
      dd[h] = true;
      res += cab.ts;
      if (cab.ts > maxTS)
        maxTS = cab.ts;
      count++;
    }
    h++;
  }
  cout << maxTS << endl;
  cout << count << endl;
  for (int i = 0; i < m; i++)
    if (dd[i])
      cout << cable[i].u << " " << cable[i].v << endl;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    edge tmp;
    tmp.u = x;
    tmp.v = y;
    tmp.ts = z;
    cable.push_back(tmp);
  }
  kruskal();
}