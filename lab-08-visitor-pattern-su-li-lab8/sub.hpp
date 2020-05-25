#ifndef __SUB_HPP__
#define __SUB_HPP__

#include <iostream>
#include <string>
#include "base.hpp"
#include "op.hpp"


class Sub: public Base {
public:
        Base* result;
        Base* left;
        Base* right;

        Sub() {};
        ~Sub() {};
        Sub (Base* new_num1, Base* new_num2){
            left = new_num1;
            right = new_num2;
            result = new Op(evaluate());
        };

        double evaluate(){
            return left -> evaluate() - right -> evaluate();
        }

        std::string stringify() {
            std::string str1 = left -> stringify();
            std::string str2 = right -> stringify();
            std::string str3 = " - ";
            std::string str = str1 + str3;
            str+=str2;
            return str;
        }
        Iterator* create_iterator(){
            return new BinaryIterator(this);
        }

         Base* get_left() {
           return this->left;
        }
         Base* get_right() {
           return this->right;
        }
        void accept(CountVisitor* visitor){visitor->visit_sub();}
};
#endif //__SUB_HPP__
