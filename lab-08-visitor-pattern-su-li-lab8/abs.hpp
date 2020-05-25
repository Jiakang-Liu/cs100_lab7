#ifndef __ABS_HPP__
#define __ABS_HPP__
#include <cmath>
#include "Decorator.hpp"

class Abs : public Decorator{
public:
    Abs():Decorator(){};
    Abs(Base* num):Decorator(num){};

    std::string stringify(){return std::to_string(std::abs(this->result->evaluate()));}
    double evaluate(){return std::abs(this->result->evaluate());}
    double abs(){return std::abs(this->result->evaluate());}
    iterator* creat_iterator(){
        return new UnaryIterator(this);
    }
    void accept(CountVisitor* visitor){
        visitor->visit_abs();
    }

    Iterator* creat_iterator(){
        return new UnaryIterator(this);
    }
};

#endif
