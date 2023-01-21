#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  N--;
  vector<int> vec(10);
  vec.at(8) = 1;
  vec.at(9) = 1;

  vec.at(2) += N % 10;
  vec.at(1) += (N / 10) % 10;
  vec.at(3) += (N / 10) % 10;
  vec.at(4) += (N / 100) % 10;
  vec.at(5) += (N / 100) % 10;
  vec.at(6) += (N / 1000) % 10;
  vec.at(7) += (N / 10000) % 10;
  vec.at(8) += (N / 100000) % 10;
  vec.at(9) += (N / 100000) % 10;

  for (int i=9; i >= 1; i--) {
    cout << vec.at(i);
  }
  cout << endl;
}

