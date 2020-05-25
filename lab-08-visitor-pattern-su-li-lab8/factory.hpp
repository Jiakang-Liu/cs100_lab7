#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "add.hpp"
#include "base.hpp"
#include "sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "op.hpp"
#include "Pow.hpp"
#include <string>
#include "Paren.hpp"
#include <locale>

using namespace std;

class Factory{
public:
    Factory(){};
    Base* parse(char** input,int length,CountVisitor* cv){
        string in,next;
        int prev_opt=0;
        Base* result = nullptr;
        int str_count = 0;
        int pos = 0;
        in = input[0];
        if (length == 0 || !isdigit(in[0])){
            return nullptr;
        }
        result = new Op(stod(in));
        for (unsigned int i = 1; i< length; ++i){
            in = input[i];next =input[i+1];
            if(in == "+" && isdigit(next[0])){
                result = new Add(result, new Op(stod(next)));
                prev_opt = 1;
                i++;
            }
            else if(in == "-" && isdigit(next[0])){
                result = new Sub(result, new Op(stod(next)));
                prev_opt = 1;
                i++;
            }
            else if(in == "*" && isdigit(next[0])){
                if(prev_opt == 1){
                    result = new Mult(new Paren(result), new Op(stod(next)));
                }
                else{
                    result = new Mult(result, new Op(stod(next)));
                }
                prev_opt = 0;
                i++;
            }
            else if(in == "/" && isdigit(next[0])){
                if(prev_opt == 1){
                    result = new Div(new Paren(result), new Op(stod(next)));
                }
                else{
                    result = new Div(result, new Op(stod(next)));
                }
                prev_opt = 0;
                i++;
            }
            else if(in == "^" && isdigit(next[0])){
                if(i!=1){
                    result = new Pow(new Paren(result), new Op(stod(next)));
                }
                else{
                    result =new Paren( new Pow(result, new Op(stod(next))));
                }
                i++;
            }
            else{
                return nullptr;
            }
            result->accept(cv);
        }
        return result;
    }
    
};

#endif
