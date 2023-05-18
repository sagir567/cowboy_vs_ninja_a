#include <iostream>
#include "Ninja.hpp"
#pragma once


#ifndef TRAINEDNINJA_HPP
#define TRAINEDINJA_HPP

using namespace std;

namespace ariel {


    class TrainedNinja : public Ninja {

    public:
        TrainedNinja(string name,Point pos);

        ~TrainedNinja();

        string print();
    };


}
#endif