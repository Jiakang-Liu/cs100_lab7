#include "selection_sort.hpp"

void SelectionSort::sort(Container* container){
           int i, j, first,temp;
           int numLength = container -> size();
           for (i = numLength -1; i >0; i--) {
                 first = 0;
                 for (j = 1; j <= i; j++){
                 if(container -> at(j) -> evaluate() < container -> at(first) -> evaluate()){
                             first = j;
                 }
           }
           temp = container -> at(first) -> evaluate();
           container -> swap(first,i);
           }
return;
            
}
