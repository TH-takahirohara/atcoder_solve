// なぜかpresentation errorになる。コード自体は合ってるはず。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  vector<int> vec;
  int tmp_n = N;
  while (true) {
    if (tmp_n == 1) break;
    
    for (int i=2; i<=sqrt(N); i++) {
      if (tmp_n % i == 0) {
        vec.push_back(i);
        tmp_n /= i;
        break;
      }
    }
  }
  
  cout << N << ":";
  rep(i,0,vec.size()) {
    cout << " " << vec.at(i);
  }
}
