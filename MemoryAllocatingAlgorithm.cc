//https://hihocoder.com/contest/hiho108/problem/1
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

struct chunk {
  int v, s, e;
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  deque<chunk> que;
  int c;
  bool f = true;
  for (int k = 1; k <= n; ++k) {
    if (f)
      scanf("%d", &c);
    if (que.empty()) {
      que.push_back({k, 0, c - 1});
    } else {
      bool flag = false;
      int minK = n + 1;
      int idx = -1;
      for (int i = 0; i < que.size(); ++i) {
        if (minK > que[i].v) {
          minK = que[i].v;
          idx = i;
        }
        if (i == 0) {
          if (c - 1 < que[i].s) {
            que.push_front({k, 0, c - 1});
            flag = true;
            break;
          }
        }
        if (i == que.size() - 1) {
          if (que[i].e + c < m) {
            que.push_back({k, que[i].e + 1, que[i].e + c});
            flag = true;
            break;
          }

        }

        else {
          if (que[i + 1].s - que[i].e - 1 >= c) {
            que.insert(que.begin() + i + 1, {k, que[i].e + 1, que[i].e + c});
            flag = true;
            break;
          }
        }
      }

      if (!flag) {
        que.erase(que.begin() + idx);
        k--;
        f = false;
      } else {
        f = true;
      }
    }
  }

  sort(que.begin(), que.end(),
       [](const chunk& ch1, const chunk& ch2) { return ch1.v < ch2.v; });
  for (int k = 0; k < que.size(); ++k) {
    printf("%d %d\n", que[k].v, que[k].s);
  }
}
