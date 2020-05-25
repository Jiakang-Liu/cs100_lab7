#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "base.hpp"

class Decorator : public Base{
	protected:
		Base *result;

		Decorator():Base(){};
    Decorator(Base* first){
        result = first;
    };

	public:
		virtual double evaluate() = 0;
};
#endif
