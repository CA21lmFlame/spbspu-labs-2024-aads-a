#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP
#include <iterator>
#include "treenode.hpp"

namespace piyavkin
{
  template< class Key, class T, class Compare >
  class Tree;
  template< class Key, class T, class Compare = std::less< Key > >
  class TreeIterator: public std::iterator< std::bidirectional_iterator_tag, T >
  {
    using val_type = std::pair< Key, T >;
    friend class Tree< Key, T, Compare >;
  public:
    TreeIterator():
      node_(nullptr),
      pair_()
    {}
    TreeIterator(const TreeIterator< Key, T, Compare >&) = default;
    TreeIterator< Key, T, Compare >& operator=(const TreeIterator< Key, T, Compare >&) = default;
    ~TreeIterator() = default;
    TreeIterator< Key, T, Compare >& operator++()
    {
      if (node_->right_)
      {
        node_ = node_->right_;
        while (node_->left_)
        {
          node_ = node_->left_;
        }
        pair_.first = node_->key_;
        pair_.second = node_->data_;
        return *this;
      }
      while (node_->parent_ && node_->parent_->right_ == node_)
      {
        node_ = node_->parent_;
      }
      node_ = node_->parent_;
      pair_.first = node_->key_;
      pair_.second = node_->data_;
      return *this;
    }
    TreeIterator< Key, T, Compare >& operator--()
    {
      if (node_->left_)
      {
        node_ = node_->left_;
        while (node_->right_)
        {
          node_ = node_->right_;
        }
        pair_.first = node_->key_;
        pair_.second = node_->data_;
        return *this;
      }
      while (node_->parent_ && node_->parent_->left_ == node_)
      {
        node_ = node_->parent_;
      }
      node_ = node_->parent_;
      pair_.first = node_->key_;
      pair_.second = node_->data_;
      return *this;
    }
    TreeIterator< Key, T, Compare > operator++(int)
    {
      TreeIterator< Key, T, Compare > result(*this);
      ++(*this);
      return result;
    }
    TreeIterator< Key, T, Compare > operator--(int)
    {
      TreeIterator< Key, T, Compare > result(*this);
      --(*this);
      return result;
    }
    bool operator==(const TreeIterator< Key, T, Compare >& rhs) const
    {
      return node_ == rhs.node_;
    }
    bool operator!=(const TreeIterator< Key, T, Compare >& rhs) const
    {
      return !(*this == rhs);
    }
    val_type* operator->()
    {
      return std::addressof(pair_);
    }
    val_type& operator*()
    {
      return pair_;
    }
    const val_type* operator->() const
    {
      return std::addressof(pair_);
    }
    const val_type& operator*() const
    {
      return pair_;
    }
  private:
    detail::Node< Key, T >* node_;
    val_type pair_;
    explicit TreeIterator(detail::Node< Key, T >* node):
      node_(node),
      pair_(node->key_, node->data_)
    {}
  };
}
#endif