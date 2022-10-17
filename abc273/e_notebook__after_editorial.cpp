// 解説後AC。ポインタを使うべきところを、参照を使って謎挙動をさせて時間を費やしてしまった。
// ポインタの値渡しを行うように書いてACした。
// ポインタの書き方の参考： https://qiita.com/yokoto/items/3bbe3754cf378d54f55c
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

struct Node {
  struct Node *par;
  int val;
};

int main() {
  int Q; cin >> Q;

  Node *nil = nullptr;
  Node *init = new Node;
  init->par = nil;
  init->val = -1;
  Node *now = init;
  map<int,Node*> mp;

  rep(i,0,Q) {
    string s; cin >> s;
    if (s == "ADD") {
      int x; cin >> x;
      Node *nx = new Node;
      nx->par = now;
      nx->val = x;
      now = nx;
    } else if (s == "DELETE") {
      if (now->val != -1) {
        Node *par = now->par;
        now = par;
      }
    } else if (s == "SAVE") {
      int y; cin >> y;
      Node *cp = new Node;
      cp->par = now->par;
      cp->val = now->val;
      mp[y] = cp;
    } else { // LOAD
      int z; cin >> z;
      if (mp.count(z)) {
        now = mp.at(z);
      } else {
        now = init;
      }
    }
    cout << now->val << " ";
  }
}
