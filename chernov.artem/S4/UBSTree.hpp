#ifndef	UBSTREE_HPP
#define	UBSTREE_HPP
#include "treeNode.hpp"
#include <functional>
#include <cstddef>

namespace chernov
{
  template < typename Key, typename Value, typename Compare = std::less< Key > >
  class UBSTree
  {
  public:
    UBSTree();
    UBSTree(UBSTree&& obj);
    ~UBSTree();

    size_t size() const;
    bool empty() const;

    Value& at(const Key& key);
    const Value& at(const Key& key) const;

  private:
    TreeNode< Key, Value >* root_;
    size_t size_;
    Compare comp_;
  };

  template < typename Key, typename Value, typename Compare >
  UBSTree< Key, Value, Compare >::UBSTree():
    root_(nullptr),
    size_(0),
    comp_()
  {}

  template < typename Key, typename Value, typename Compare >
  UBSTree< Key, Value, Compare >::UBSTree(UBSTree&& obj):
    root_(obj.root_),
    size_(obj.size_),
    comp_(obj.comp_)
  {
    obj.root_ = nullptr;
    obj.size_ = 0;
  }

  template < typename Key, typename Value, typename Compare >
  UBSTree< Key, Value, Compare >::~UBSTree()
  {}

  template < typename Key, typename Value, typename Compare >
  size_t UBSTree< Key, Value, Compare >::size() const
  {
    return size_;
  }

  template < typename Key, typename Value, typename Compare >
  bool UBSTree< Key, Value, Compare >::empty() const
  {
    return size_ == 0;
  }

  template < typename Key, typename Value, typename Compare >
  Value& UBSTree< Key, Value, Compare >::at(const Key& key)
  {}

  template < typename Key, typename Value, typename Compare >
  const Value& UBSTree< Key, Value, Compare >::at(const Key& key) const
  {}
}

#endif
