#include <iostream>

using namespace std;
const int64_t maxn = 10000 + 10;
int64_t n;
struct point64_t {
  int64_t x;
  int64_t y;
};
point64_t arr[maxn];
void input() {
  cin >> n;
  for (int64_t i = 0; i < n; i++)
    cin >> arr[i].x >> arr[i].y;
}

bool clockwise(int64_t x1, int64_t y1, int64_t x2, int64_t y2, int64_t x3,
               int64_t y3) {
  return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) < 0);
}

void solve() {
  int64_t count = 0;
  int64_t mid = (n - 2) / 2;
  for (int64_t i = 1; i < n; i++) {
    count = 0;
    for (int64_t j = 1; j < n && count <= mid; j++)
      if (j != i) {
        if (clockwise(arr[0].x, arr[0].y, arr[i].x, arr[i].y, arr[j].x,
                      arr[j].y))
          count++;
      }
    if (count == mid) {
      cout << "1 " << i + 1;
      return;
    }
  }
}

int main() {
  input();
  solve();
}