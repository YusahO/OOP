#pragma once

#include <memory>

template<typename T>
class BaseTreeNode;

template<typename T>
using BaseTreeParentPtr = std::weak_ptr<BaseTreeNode<T>>;

template<typename T>
using BaseTreeChildPtr = std::shared_ptr<BaseTreeNode<T>>;


template<typename T>
class BaseTreeNode
{
public:
    BaseTreeNode(const T &value, const BaseTreeChildPtr<T> parent);
    virtual ~BaseTreeNode() = default;

    BaseTreeParentPtr<T> GetParent() const;
    BaseTreeChildPtr<T> GetLeft() const;
    BaseTreeChildPtr<T> GetRight() const;

protected:
    T m_value;
    BaseTreeParentPtr<T> mp_parent;
    BaseTreeChildPtr<T> mp_left;
    BaseTreeChildPtr<T> mp_right;
};
