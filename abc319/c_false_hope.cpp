#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

bool gakkari(int i, vector<bool> seen, vector<int> orig) {
  vector<vector<int>> chs;
  if (i==0) chs = {{1,2}, {3,6}, {4,8}};
  else if (i==1) chs = {{0,2}, {4,7}};
  else if (i==2) chs = {{0,1}, {5,8}, {4,6}};
  else if (i==3) chs = {{0,6}, {4,5}};
  else if (i==4) chs = {{1,7}, {3,5}, {0,8}, {2,6}};
  else if (i==5) chs = {{2,8}, {3,4}};
  else if (i==6) chs = {{0,3}, {2,4}, {7,8}};
  else if (i==7) chs = {{1,4}, {6,8}};
  else if (i==8) chs = {{0,4}, {2,5}, {6,7}};

  for (auto ch : chs) {
    int n1 = ch.at(0);
    int n2 = ch.at(1);
    if (seen.at(n1) && seen.at(n2) && orig.at(n1) == orig.at(n2)) {
      return true;
    }
  }
  return false;
}

int main() {
  vector<int> vec(9);
  rep(i,0,9) {
    cin >> vec.at(i);
  }

  // rep(i,0,9) cout << vec.at(i) << " ";
  // cout << endl;

  vector<int> jun = {0,1,2,3,4,5,6,7,8};
  int al = 9*8*7*6*5*4*3*2*1;
  int sum = 0;
  do {
    bool is_gak = false;
    vector<bool> seen(9, false);
    rep(i,0,9) {
      if (gakkari(jun.at(i), seen, vec)) {
        is_gak = true;
      }
      seen.at(jun.at(i)) = true;
    }
    if (!is_gak) sum++;
  } while (next_permutation(jun.begin(), jun.end()));
  // cout << sum << endl;
  cout << fixed << setprecision(10) << (double)sum / al << endl;
}
