#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
#include "Floor.hpp"
#include "iterator.hpp"

TEST(IteratorTest, BinIt) {
    Base* test = new Add(new Op(5), new Op(6));

    Iterator* it = test->create_iterator();

    EXPECT_EQ(it->current()->evaluate(), 5);
    it->next();
    EXPECT_EQ(it->current()->evaluate(), 6);
}

TEST(IteratorTest, NullIt) {
    Base* test = new Op(8);

    EXPECT_EQ(test->create_iterator()->current(), nullptr);
}

TEST(IteratorTest, UnaryIt) {
    Base* test = new Floor(new Op(4.2));
    Iterator *it = test->create_iterator();
    EXPECT_EQ(it->current()->evaluate(), 4);
}

#endif
