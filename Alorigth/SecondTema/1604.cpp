#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 10;

int k;

struct sign {
  int number;
  int pos;
};
sign arr[maxn];

struct compare {
  bool operator()(sign &a, sign &b) const { return a.number < b.number; }
};

void input() {
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> arr[i].number;
    arr[i].pos = i + 1;
  }
}

int main() {
  input();
  vector<sign> v(arr, arr + k);
  make_heap(v.begin(), v.end(), compare());
  while (v.size() >= 2) {
    pop_heap(v.begin(), v.end(), compare());
    sign tmp1 = v.back();
    v.pop_back();

    pop_heap(v.begin(), v.end(), compare());
    sign tmp2 = v.back();
    v.pop_back();

    cout << tmp1.pos << " " << tmp2.pos << " ";

    tmp1.number--;
    tmp2.number--;
    if (tmp1.number > 0)
      v.push_back(tmp1);
    push_heap(v.begin(), v.end(), compare());
    if (tmp2.number > 0)
      v.push_back(tmp2);
    push_heap(v.begin(), v.end(), compare());
  }
  if (v.size() != 0) {
    pop_heap(v.begin(), v.end(), compare());
    sign tmp1 = v.back();
    v.pop_back();
    for (int i = 0; i < tmp1.number; i++)
      cout << tmp1.pos << " ";
  }
}
