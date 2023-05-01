#pragma once

#include <memory>

template <typename T>
class TreeNode;

template <typename T>
using BSTSharedPtr = std::shared_ptr<TreeNode<T>>;

template <typename T>
using BSTWeakPtr = std::weak_ptr<TreeNode<T>>;

#include "TreeNode.h"