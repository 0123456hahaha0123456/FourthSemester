#include <stack>
#include <iostream>
#include <vector>

using namespace std;

const int64_t maxn = 100000 + 10;
int64_t n;

vector<int64_t> arr;
stack<int64_t> st;

void input() {
  cin >> n;
  for (int64_t i = 0; i < n; i++) {
    int64_t x;
    cin >> x;
    arr.push_back(x);
  }
}
void solve() {
  int64_t i = 1;
  int64_t j = 0;
  st.push(i);
  while (j < n) {
    if (!st.empty() && (arr[j] == st.top())) {
      j++;
      st.pop();
    } else if (!st.empty() && (arr[j] < st.top())) {
      cout << "Cheater";
      return;
    } else {
      i++;
      st.push(i);
    }
  }
  cout << "Not a proof";
}

int main() {
  input();
  solve();
}