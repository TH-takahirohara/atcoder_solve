#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  vector<int> vec(N,0);
  rep(i,0,N) cin >> vec.at(i);
  
  sort(vec.begin(), vec.end());
  
  int now = 0;
  rep(i,0,N) {
    if (vec.at(i) == now) now++;
  }
  
  cout << now << endl;
}
