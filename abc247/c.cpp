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

string saiki(int num) {
  if (num == 1) {
    return "1";
  }
    
  return saiki(num-1) + to_string(num) + saiki(num-1);
}

vector<int> saikin(int num) {
  if (num==1) {
    return {1};
  }
  
  vector<int> vec = {};
  vector<int> sai = saikin(num-1);
  rep(i,0,sai.size()) {
    vec.push_back(sai.at(i));
  }
  vec.push_back(num);
  rep(i,0,sai.size()) {
    vec.push_back(sai.at(i));
  }
  return vec;
}

int main() {
  int N;
  cin >> N;
  
  vector<int> ans = saikin(N);
  rep(i,0,ans.size()) {
    if (i!=(ans.size()-1)) cout << ans.at(i) << " ";
    else cout << ans.at(i) << endl;
  }
}
