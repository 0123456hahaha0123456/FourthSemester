#include <iostream>
#include <string>
#include <cstddef>
#include <map>

using namespace std;
const int maxn = 100;
int n;

struct tree {
  tree() {
    this->value = "";
    this->child = {};
  }

  tree(string value) {
    this->value = value;
    this->child = {};
  }

  tree(string value, map<string, tree *> child) {
    this->value = value;
    this->child = child;
  }
  string value;
  map<string, tree *> child;
};

void output(tree *root, int tab) {
  for (int i = 0; i < tab; i++)
    cout << " ";
  if (root->value != "") {
    cout << root->value << endl;
  }
  tab++;
  for (auto &i : root->child) {
    output(i.second, tab);
  }
}

int main() {
  cin >> n;
  tree *root = new tree();

  for (int i = 0; i < n; i++) {
    string s;
    string value = "";
    cin >> s;
    tree *tmp = root;
    for (int j = 0; j <= s.length(); j++) {

      if (s[j] == '\\' || s[j] == '\0') {
        auto dir_value = tmp->child.find(value);
        if (dir_value == tmp->child.end()) {
          tree *new_node = new tree(value);
          tmp->child.insert(pair<string, tree *>(value, new_node));
          tmp = tmp->child.find(value)->second;
        } else {
          tmp = dir_value->second;
        }
        value = "";
      } else
        value += s[j];
    }
  }

  output(root, -1);
}