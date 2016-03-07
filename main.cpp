#include <iostream>

#include <vector>
#include "DataStructures/segment_tree.h"

using namespace std;

int main() {
  std::vector<int> v = {1, 2, 3};
  segment_tree<int> st(v);
  st.set(1, 4);
  cout << st.get(0, 3) << endl;
  return 0;
}
