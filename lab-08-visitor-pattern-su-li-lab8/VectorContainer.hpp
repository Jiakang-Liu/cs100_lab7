#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__
#include "container.hpp"
#include <iostream>
#include <vector>
#include "base.hpp"
//using namespace std;

class VectorContainer : public Container{
protected:
    vector<Base*> vct_ctn;
public:
    VectorContainer(): Container() { };
    
    void add_element(Base* element){
        vct_ctn.push_back(element);
    }
    // iterate through trees and output the expressions (use stringify())
    void print(){
        Base* temp;
        for(unsigned int i=0; i< vct_ctn.size();++i){
            temp = vct_ctn[i];
            std::cout<<temp->stringify()<<" ";
        }
        cout<<endl;
    }
    // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
    void sort(){
        sort_function->sort(this);
    }

    /* Essentially the only functions needed to sort */
    //switch tree locations
    void swap(int i, int j){
        std::swap(vct_ctn[i], vct_ctn[j]);
    }
    // get top ptr of tree at index i
    Base* at(int i){
        return vct_ctn.at(i);
    }
    // return container size
    int size(){
        return vct_ctn.size();
    }
};

#endif
