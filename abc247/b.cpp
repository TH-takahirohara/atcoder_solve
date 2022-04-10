#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

double PI = 3.14159265359;

struct UnionFind {
  vector<ll> par, siz;
  
  UnionFind(ll n) : par(n,-1), siz(n,1) {}
  
  ll root(ll x) {
    if (par.at(x) == -1) return x;
    else return par.at(x) = root(par.at(x));
  }
  
  bool issame(ll x, ll y) {
    return root(x) == root(y);
  }
  
  bool unite(ll x, ll y) {
    x = root(x); y = root(y);
    
    if (x == y) return false;
    
    if (siz.at(x) < siz.at(y)) swap(x, y);
    
    par.at(y) = x;
    siz.at(x) += siz.at(y);
    return true;
  }
  
  ll size(ll x) {
    return siz.at(root(x));
  }
};

int main() {
  int N;
  cin >> N;
  vector<string> myo(N), mei(N);
  vector<string> adana(N);
  
  rep(i,0,N) {
    cin >> myo.at(i) >> mei.at(i);
  }
  
  vector<string> adanas(N, "");
  bool ans = true;
  rep(i,0,N) {
    string adana;
    string myoji = myo.at(i);
    string namae = mei.at(i);
    bool can_myo = true;
    bool can_mei = true;
    rep(j,0,N) {
      if (i==j) continue;
      if (myoji == myo.at(j) && namae == mei.at(j)) {
        can_myo = false;
        can_mei = false;
        break;
      } else if (myoji == myo.at(j) || namae == myo.at(j)) {
        can_myo = false;
        //break;
      } else if (namae == mei.at(j) || myoji == mei.at(j)) {
        can_mei = false;
        //break;
      }
    }
    
    if (!can_mei && !can_myo) {
      ans = false;
      break;
    } else if (can_mei) {
      adana = namae;
    } else {
      adana = myoji;
    }
    
    adanas.at(i) = adana;
    rep(k,0,N) {
      if (i==k) continue;
      if (adanas.at(k) == adana) {
        ans = false;
        break;
      }
    }
    
    if (!ans) {
      break;
    }
  }
  
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
