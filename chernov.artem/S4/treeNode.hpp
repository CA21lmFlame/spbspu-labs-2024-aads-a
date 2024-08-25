#ifndef	TREE_NODE_HPP
#define	TREE_NODE_HPP
#include <utility>

namespace chernov
{
  template < typename Key, typename Value >
  struct TreeNode
  {
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    std::pair< Key, Value > data;

    TreeNode(const Key& key, const Value& value):
      left(nullptr),
      right(nullptr),
      parent(nullptr),
      data(std::make_pair(key, value)
    {}

    ~TreeNode() = default;
  };
}

#endif
