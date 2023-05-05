#pragma once

#include <memory>

template <typename T>
concept Comparable = std::totally_ordered<T>;


namespace MyBST {

template <typename T>
class TreeNode;

template <typename T>
using BSTSharedPtr = std::shared_ptr<TreeNode<T>>;

template <typename T>
using BSTWeakPtr = std::weak_ptr<TreeNode<T>>;

}

#include "TreeNode.hpp"