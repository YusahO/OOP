#pragma once

#include <memory>


namespace MyBST {

template <typename T>
concept Comparable = std::totally_ordered<T>;

template <typename T>
concept Container = requires (T t)
{
    typename T::value_type;

    { *t.begin() } -> std::same_as<typename T::value_type&>;
    { t.begin() } -> std::same_as<typename T::iterator>;
    { t.end() } -> std::same_as<typename T::iterator>;
};

template <typename From, typename To>
concept Assignable = requires (From fm, To to)
{
    to = fm;
};

template <typename From, typename To>
concept Convertible = std::convertible_to<From, To>;


template <typename T>
class TreeNode;

template <typename T>
using BSTSharedPtr = std::shared_ptr<TreeNode<T>>;

template <typename T>
using BSTWeakPtr = std::weak_ptr<TreeNode<T>>;

}

#include "TreeNode.hpp"