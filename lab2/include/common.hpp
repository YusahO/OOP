#pragma once

#include <memory>


namespace MyBST {

template <typename T>
concept Comparable = std::totally_ordered<T>;

template <typename T>
concept Container = requires (T t)
{
    { t.begin() } -> std::same_as<typename T::iterator>;
    { t.end() } -> std::same_as<typename T::iterator>;
};


template <typename T>
class TreeNode;

template <typename T>
using BSTSharedPtr = std::shared_ptr<TreeNode<T>>;

template <typename T>
using BSTWeakPtr = std::weak_ptr<TreeNode<T>>;

}

#include "TreeNode.hpp"