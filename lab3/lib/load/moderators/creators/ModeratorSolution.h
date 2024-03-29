#pragma once

#include <memory>

template<typename Tcreator>
class ModeratorSolution
{
public:
    decltype(auto) create();
};

template<typename Tcreator>
decltype(auto) ModeratorSolution<Tcreator>::create()
{
    auto creator = Tcreator();
    auto moderator = creator.createModerator();

    return moderator;
}
