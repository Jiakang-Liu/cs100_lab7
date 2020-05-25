#ifndef __PAREN_HPP__
#define __PAREN_HPP__
#include "string_modify.hpp"
#include <string>
//using namespace std;

class Paren : public StringModify{
public:
    Paren() : StringModify(){};
    Paren(Base* num) : StringModify(num){};
    double evaluate() {return this->result_str -> evaluate();}
    std::string stringify(){
        std::string result = "(";
        result += this->result_str->stringify();
        result += ")";
        return result;
    }
    std::string paren(){
        std::string result = "(";
        result += this->result_str->stringify();
        result += ")";
        return result;
    }
    void accept(CountVisitor* visitor){visitor->visit_paren();}
    Iterator* create_iterator(){
        return new UnaryIterator(this);
    }
    Base* get_left(){return this;}
    Base* get_right(){return nullptr;}
};



#endif

