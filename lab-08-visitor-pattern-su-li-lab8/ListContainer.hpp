#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__
#include "container.hpp"
#include <iostream>
#include <list>
#include "base.hpp"
//using namespace std;

class ListContainer : public Container{
protected:
    list<Base*> lst_cnt;
    
public:
    ListContainer() : Container(){};
    void add_element(Base* element){
        lst_cnt.push_back(element);
    }
    // iterate through trees and output the expressions (use stringify())
    void print(){
        std::string result;
        Base* temp;
        list<Base*>::iterator result_temp = lst_cnt.begin();
        for (unsigned int i =0; i<lst_cnt.size(); ++i) {
            temp = *result_temp;
            std::cout<<temp->stringify()<<" ";
            result_temp = next(lst_cnt.begin(),i+1);
        }
        cout<<endl;
    }
    // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
    void sort(){
         std::cout<<"sort"<<std::endl;
	 if(sort_function == nullptr){
		std::cout<<"error"<<std::endl;
	}
	 sort_function->sort(this);
	std::cout<<"end"<<std::endl;
    }
        
    /* Essentially the only functions needed to sort */
    //switch tree locations
    void swap(int i, int j){
        list<Base*>::iterator result_temp1 = next(lst_cnt.begin(),i),result_temp2 = next(lst_cnt.begin(),j);
        Base* first = *result_temp1;
        Base* second = *result_temp2;
        *result_temp1 = second;
        *result_temp2 = first;
    }
    // get top ptr of tree at index i
    Base* at(int i){
        list<Base*>::iterator result_temp = next(lst_cnt.begin(),i);
        return *result_temp;
    }
    // return container size
    int size(){
        return lst_cnt.size();
    }
};

#endif
