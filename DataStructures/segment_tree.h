//
// Created by Anton Kovsharov on 3/8/16.
//

#ifndef SUBMITPORN_SEGMENT_TREE_H
#define SUBMITPORN_SEGMENT_TREE_H

#include <vector>

template <typename T>
struct sum_composer {
  T operator()(T const & a, T const & b) const {
    return a + b;
  }
};

template <typename T>
struct min_composer {
   T operator()(T const & a, T const & b) const {
    return std::min(a, b);
  }
};

template <typename T>
struct max_composer {
   T operator()(T const & a, T const & b) const {
    return std::max(a, b);
  }
};

template <typename T, template<typename> class Composer >
class segment_tree {
public:
  int n;
  std::vector<T> const & a;
  std::vector<T> t;
  Composer<T> composer;

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
    t[v] = composer(t[2 * v + 1], t[2 * v + 2]);
  }

  T get(int v, int tl, int tr, int l, int r) {
    if (tl >= l && tr <= r) {
      return t[v];
    }
    if (tl >= r || tr <= l) {
      return 0;
    }
    int tm = (tl + tr) / 2;
    return composer(get(2 * v  +1, tl, tm, l, r), get(2 * v + 2, tm, tr, l, r));
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
    t[v] = composer(t[2 * v + 1], t[2 * v + 2]);
  }
};

template <typename T>
  using sum_segment_tree = segment_tree<T, sum_composer>;
template <typename T>
  using min_segment_tree = segment_tree<T, min_composer>;
template <typename T>
  using max_segment_tree = segment_tree<T, max_composer>;
#endif //SUBMITPORN_SEGMENT_TREE_H
