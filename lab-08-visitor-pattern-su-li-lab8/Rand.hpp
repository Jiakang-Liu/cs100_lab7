#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "base.hpp"

class Rand : public Base {
	public:
		Rand() : Base() {
			srand (0);
			num = rand() % 100;
		}
		~ Rand () {};

		double  evaluate() {
			double new_num;
			new_num = static_cast<double>(num);
			return new_num;
		}
    void accept(CountVisitor* visitor){visitor->visit_rand();}
		std::string stringify() {
			std::string str = std::to_string(num);
			return str;
		}
    Iterator* create_iterator(){
        return new NullIterator(this);
    }
	private:
		int num;
};

#endif 
