#ifndef __STRING_MODIFY_HPP__
#define __STRING_MODIFY_HPP__
#include "base.hpp"
//using namespace std;
class StringModify :public Base{
protected:
    Base* result_str;
    
    StringModify():Base(){};
    StringModify(Base* modifyThis){
        result_str = modifyThis;
    };
public:
    virtual std::string stringify() = 0;
};


#endif
