//
// Created by Anton Kovsharov on 3/8/16.
//

#ifndef SUBMITPORN_SEGMENT_TREE_H
#define SUBMITPORN_SEGMENT_TREE_H

#include <vector>

template <typename T>
class segment_tree {
public:
  std::vector<T> const & v;

  segment_tree(std::vector<T> const & v)
    : v(v)
  {
  }

  T get(int l, int r)
  {
    return v[0];
  }

  void set(int l, int r, int i, T val) {
  }
};

#endif //SUBMITPORN_SEGMENT_TREE_H
