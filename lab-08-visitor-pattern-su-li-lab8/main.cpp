#include <iostream>
#include "base.hpp"
#include "factory.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    Base* result;
    CountVisitor* cv = new CountVisitor();
    string x = argv[1];
    Factory expression;
    argv++;
    result = expression.parse(argv, argc-1,cv);
    cout<<"add: "<<cv->add_count()<<endl<<"sub: "<<cv->sub_count()<<endl<<"mult: "<<cv->mult_count()<<endl<<"div: "<<cv->div_count()<<endl<<"pow: "<<cv->pow_count()<<endl<<"ceil: " <<cv->ceil_count()<<endl<<"floor: "<<cv->floor_count()<<endl;
    cout << result -> stringify() << " = " << result -> evaluate()<<endl;
	
    return 0;
}


