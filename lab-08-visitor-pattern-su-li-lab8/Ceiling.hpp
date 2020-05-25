#ifndef __CEILING_HPP__
#define __CEILING_HPP__

#include <cmath>
#include "Decorator.hpp"

class Ceiling : public Decorator {
public:
	Ceiling() : Decorator() {};
	Ceiling(Base* num) : Decorator(num) {};
    std::string stringify(){return ::to_string(:: ceil(this -> result -> evaluate()));}
	double evaluate () {
		return :: ceil(this -> result -> evaluate());
	};

	int ceil(){
		return :: ceil(this -> result -> evaluate());
	}
    Iterator* create_iterator(){
        return new UnaryIterator(this);
    }
    void accept(CountVisitor* visitor){
        visitor->visit_ceil();
    }
    Base* get_left(){return this;}
    Base* get_right(){return nullptr;}
};

#endif
