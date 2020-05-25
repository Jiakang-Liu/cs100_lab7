#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include <cmath>
#include "Decorator.hpp"

class Floor : public Decorator {
	public:
		Floor() : Decorator() {};
		Floor(Base* num) : Decorator(num) {};
        std::string stringify(){return ::to_string(::floor(this-> result ->evaluate()));}
		double evaluate() {
			return ::floor(this-> result ->evaluate());
		};
        int floor() {
			return ::floor(this-> result ->evaluate());
		};

        Iterator* create_iterator(){
            return new UnaryIterator(this);
        }
        void accept(CountVisitor* visitor){
            visitor->visit_floor();
        }
    Base* get_left(){return this;}
    Base* get_right(){return nullptr;}
};

#endif
