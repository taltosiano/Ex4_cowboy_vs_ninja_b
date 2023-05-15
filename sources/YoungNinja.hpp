#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Ninja.hpp"


namespace ariel
{
    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string name, Point location);

    };
}

#endif