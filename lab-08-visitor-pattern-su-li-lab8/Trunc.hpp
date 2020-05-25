#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__
#include "string_modify.hpp"
#include <string>
//using namespace std;
class Trunc : public StringModify {
public:
    Trunc() : StringModify(){};
    Trunc(Base* num) : StringModify(num){};
    double evaluate(){return this->result_str->evaluate();}
    std::string stringify(){
        return std::to_string(this->result_str->evaluate());
    }
    std::string trunc(){
        return std::to_string(this->result_str->evaluate());
    }
    Iterator* creat_iterator(){
        return new UnaryIterator(this);
    }
    void accept(CountVisitor* visitor){visitor->visit_trunc();}
    Base* get_left(){return this;}
    Base* get_right(){return nullptr;}
};


#endif
