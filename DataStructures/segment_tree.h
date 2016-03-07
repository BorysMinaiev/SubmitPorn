//
// Created by Anton Kovsharov on 3/8/16.
//

#ifndef SUBMITPORN_SEGMENT_TREE_H
#define SUBMITPORN_SEGMENT_TREE_H

#include <vector>

template <typename T>
class segment_tree {
public:
  int n;
  std::vector<T> const & a;
  std::vector<T> t;

  segment_tree(std::vector<T> const & a)
    : a(a)
  {
    n = a.size();
    t.resize(4 * n);
    build(0, 0, n);
  }

  T get(int l, int r) {
    return get(0, 0, n, l, r);
  }

  void set(int i, T val) {
    set(0, 0, n, i, val);
  }

private:
  void build(int v, int tl, int tr) {
    if (tr - tl == 1) {
      t[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm, tr);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }

  T get(int v, int tl, int tr, int l, int r) {
    if (tl >= l && tr <= r) {
      return t[v];
    }
    if (tl >= r || tr <= l) {
      return 0;
    }
    int tm = (tl + tr) / 2;
    return get(2 * v  +1, tl, tm, l, r) + get(2 * v + 2, tm, tr, l, r);
  }

  void set(int v, int tl, int tr, int i, T val) {
    if (tr - tl == 1) {
      t[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (i < tm) {
      set(2 * v + 1, tl, tm, i, val);
    } else {
      set(2 * v + 2, tm, tr, i, val);
    }
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
};

#endif //SUBMITPORN_SEGMENT_TREE_H
