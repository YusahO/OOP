#pragma once

#include "BaseBinaryTree.h"

template <typename T, typename Compare>
BaseTreeRootPtr<T> BaseBinaryTree<T, Compare>::GetRoot() const noexcept
{
    return mp_root;
}
