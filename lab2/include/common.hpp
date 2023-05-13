#pragma once

#include <memory>

namespace MyAVLTree {

template <typename T>
concept Comparable = std::totally_ordered<T>;

template <typename T>
concept Container = requires (T t)
{
    typename T::value_type;
    
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
concept Iterator = requires (T t, T p)
{   
    typename T::value_type;

    { ++t } -> std::same_as<T&>;
    { --t } -> std::same_as<T&>;

    { *t } -> std::same_as<typename T::value_type const&>;
    { t != p } -> std::same_as<bool>;
};


// template <Comparable T>
// class AVLTree;

// template <Comparable T>
// using BSTSharedPtr = std::shared_ptr<AVLTree<T>::TreeNode>;

// template <Comparable T>
// using BSTWeakPtr = std::weak_ptr<AVLTree<T>::TreeNode>;

}

// #include "TreeNode.hpp"
#include "AVLTree.hpp"
