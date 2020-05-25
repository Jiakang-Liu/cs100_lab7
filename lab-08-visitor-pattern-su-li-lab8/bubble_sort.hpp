#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "container.hpp"
#include "sort.hpp"
#include <iostream>
using namespace std;

class BubbleSort : public Sort {
    public:
    void sort(Container* container);
};
#endif


