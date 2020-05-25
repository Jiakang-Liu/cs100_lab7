#include "iterator.hpp"

UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {
    this->c = left;
}

void UnaryIterator::first() { 
    this->c = left; 
}
void UnaryIterator::next() {
    if(this->c == left) {
        this->c = end1;
    }
    this->c = end1;
}
bool UnaryIterator::is_done() { 
    if(this->c == end1) {
        return true;
    }
    return false;
}
Base* UnaryIterator::current() { 
    if(this->c == left) {
        return this->self_ptr->get_left();
    }
    return nullptr;
}
