#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};

int main() {
  int N;
  string T;
  
  cin >> N >> T;
  
  int now_x = 0;
  int now_y = 0;
  pair<int,int> zahyou = make_pair(0,0);
  int dir_i = 0;
  rep(i,0,N) {
    if (T.at(i) == 'S') {
      now_x += dx.at(dir_i);
      now_y += dy.at(dir_i);
    } else {
      dir_i = (dir_i + 1) % 4;
    }
  }
  
  cout << now_x << " " << now_y << endl;
}
