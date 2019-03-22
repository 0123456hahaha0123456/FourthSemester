#include <bits/stdc++.h>

const int maxn = 8;
const int maxedge = 32;
// int a,b,c,d,e,f,g,h;
int arr[maxn];
int _count;

std::string edge[maxedge] = {"AB", "AD", "AE", "AG", "CB", "CD", "CE", "CG",
                             "FB", "FD", "FE", "FG", "HB", "HD", "HE", "HG",
                             "BA", "DA", "EA", "GA", "BC", "DC", "EC", "GC",
                             "BF", "DF", "EF", "GF", "BH", "DH", "EH", "GH"};
std::string ans[maxedge] = {
    "AB-",           "AD-",           "AE-",           "EH+\nAE-\nHG-",
    "CB-",           "CD-",           "DA+\nCD-\nAE-", "CG-",
    "FB-",           "EH+\nFE-\nHD-", "FE-",           "FG-",
    "DA+\nHD-\nAB-", "HD-",           "HE-",           "HG-",
    "BA-",           "DA-",           "EA-",           "EH+\nAE-\nHG-",
    "BC-",           "DC-",           "DA+\nCD-\nAE-", "GC-",
    "BF-",           "EH+\nFE-\nHD-", "EF-",           "GF-",
    "DA+\nHD-\nAB-", "DH-",           "EH-",           "GH-"};

int get_number(char x) {
  // std::cout << a<<b<<c<<d<<e<<f<<g<<h<<'\n';
  switch (x) {
  case 'A':
    return arr[0];
  case 'B':
    return arr[1];
  case 'C':
    return arr[2];
  case 'D':
    return arr[3];
  case 'E':
    return arr[4];
  case 'F':
    return arr[5];
  case 'G':
    return arr[6];
  case 'H':
    return arr[7];
  }
  return 0;
}

void change(char x) {
  switch (x) {
  case 'A':
    arr[0]--;
    break;
  case 'B':
    arr[1]--;
    break;
  case 'C':
    arr[2]--;
    break;
  case 'D':
    arr[3]--;
    break;
  case 'E':
    arr[4]--;
    break;
  case 'F':
    arr[5]--;
    break;
  case 'G':
    arr[6]--;
    break;
  case 'H':
    arr[7]--;
    break;
  }
}

void check_edge(std::string s, std::string &res, int i) {
  while ((get_number(s[0]) > 0) && (get_number(s[1]) > 0)) {
    //_count ++;
    change(s[0]);
    change(s[1]);
    // for (int i =0;i<maxn;i++) std::cout << arr[i];
    // res += ans[i+1];
    res += ans[i];
    res += "\n";
  }
}
bool check_after() {
  int res = 0;
  for (int i = 0; i < maxn; i++)
    res += arr[i];
  return (res == 0);
}
void solve() {
  std::string res = "";
  for (int i = 0; i < maxedge; i++) {
    check_edge(edge[i], res, i);
  }
  if (!check_after())
    std::cout << "IMPOSSIBLE";
  else
    std::cout << res;
}

int main() {
  _count = 0;
  for (int i = 0; i < maxn; i++)
    std::cin >> arr[i];
  // std::cin >>a>>b>>c>>d>>e>>f>>g>>h;
  solve();
  std::cout << '\n';
  return 0;
}