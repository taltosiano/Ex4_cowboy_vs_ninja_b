#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Ninja.hpp"


namespace ariel
{
    class OldNinja : public Ninja
    {
        public:
            OldNinja(string name, Point location);
    };
}

#endif