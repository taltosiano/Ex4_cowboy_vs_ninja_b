#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Ninja.hpp"


namespace ariel
{
    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja();
            TrainedNinja(string name, Point location);

    };
}

#endif