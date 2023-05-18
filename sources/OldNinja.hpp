#include <iostream>
#include "Ninja.hpp"


#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

using namespace std;

namespace ariel {


    class OldNinja : public Ninja {

    public:
        OldNinja(string name, Point pos);

        ~OldNinja();

        string print();
    };


}
#endif