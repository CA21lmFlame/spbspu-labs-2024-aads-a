#ifndef	UBSTREE_HPP
#define	UBSTREE_HPP
#include "treeNode.hpp"
#include <functional>

namespace chernov
{
  template < typename Key, typename Value, typename Compare = std::less< Key > >
  class UBSTree
  {
  public:
    UBSTree():
      root_(nullptr),
      size_(0),
      comp_()
    {}
  private:
    TreeNode< Key, Value >* root_;
    size_t size_;
    Compare comp_;
  };
}

#endif
