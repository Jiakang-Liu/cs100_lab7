#ifndef __POW_HPP__
#define __POW_HPP__

#include <iostream>
#include <string>
#include "base.hpp"
#include "op.hpp"


class Pow : public Base{
    public:
        Base* result;
        Base* left;
        Base* right;

        Pow(){};
        ~Pow(){};
        Pow(Base* new_num, Base* new_pow){
            left = new_num;
            right = new_pow;
            result = new Op(evaluate());
        };

        double evaluate(){
            double Result = left -> evaluate();
            if (right -> evaluate() == 0){
                Result = 1.0;
            }
            else{
                for(unsigned int i=1; i< right -> evaluate(); ++i){
                    Result*= left -> evaluate();
                }
            }
            return Result;
        }

        std::string stringify(){
            std::string str1 = left -> stringify();
            std::string str2 = right -> stringify();
            std::string str3 = " ** ";
            std::string str = str1 + str3;
            str+=str2;
            return str;
        }
         Iterator* create_iterator(){
            return new BinaryIterator(this);
        }
    void accept(CountVisitor* visitor){visitor->visit_pow();}

         Base* get_left() {
           return this->left;
        }
         Base* get_right() {
           return this->right;
        }

};
#endif //__POW_HPP__
