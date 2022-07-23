#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef pair<int,int> P;

int main() {
  int N,K;
  cin >> N >> K;
  
  vector<int> vec(N);
  
  rep(i,0,N) {
    int a,b,c;
    cin >> a >> b >> c;
    vec.at(i) = a+b+c;
  }
  
  vector<int> sv = vec;
  
  sort(sv.begin(), sv.end());
  
  rep(i,0,N) {
    int num = N - (upper_bound(sv.begin(), sv.end(), vec.at(i) + 300) - sv.begin());
    if (num < K) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

