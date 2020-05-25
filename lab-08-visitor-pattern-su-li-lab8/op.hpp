#ifndef __OP_HPP__
#define __OP_HPP__

#include <iostream>
#include <string>
#include "base.hpp"

class Op : public Base {
    public:
	Op() {};

    Op(double value) : Base() {
		num = value;
	}

	~ Op () {};

    double evaluate() {
		return num;
	}
    std::string stringify() {
        std::string str = std::to_string(num);
        return str;
	}
    void accept(CountVisitor* visitor){
        visitor->visit_op();
    }
    Iterator* create_iterator(){
        return new NullIterator(this);
    }
    Base* get_left(){
        return nullptr;
    }
    Base* get_right(){
        return nullptr;
    }
    private:
	double num;
};

#endif //__OP_HPP__
