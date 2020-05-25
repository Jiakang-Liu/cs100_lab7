#ifndef __DIV_HPP__
#define __DIV_HPP__

#include <iostream>
#include <string>
#include "op.hpp"

#include "base.hpp"

class Div: public Base {
	public:
        Base* result;
        Base* left;
        Base* right;

		Div() {};
		~ Div() {};
		Div (Base* new_num1, Base* new_num2) {
			left = new_num1;
			right = new_num2;
			result = new Op(evaluate());
		};

		double evaluate() {
			return left -> evaluate() / right -> evaluate();
		}

		std:: string stringify() {
			std::string str1 = left -> stringify();
			std::string str3 = right -> stringify();
			std::string str2 = " / ";
			std::string str = str1 + str2;
			str = str + str3;
			return str;
		}
        Iterator* create_iterator(){
            return new BinaryIterator(this);
        }
        void accept(CountVisitor* visitor){
            visitor->visit_div();
        }

        Base* get_left() {
           return this->left;
        }
        Base* get_right() {
           return this->right;
        }

};

#endif
