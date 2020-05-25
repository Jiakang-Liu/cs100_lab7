
#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "visitor.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "op.hpp"
#include "Pow.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "Ceiling.hpp"
#include "Floor.hpp"
#include "gtest/gtest.h"

TEST(VisitorTest, TestVal) {
    CountVisitor *cv = new CountVisitor();

    Base *b1 = new Add(new Op(8.2), new Op(8.4));
    b1->accept(cv);

    Base *b2 = new Sub(b1, new Op(4));
    b2->accept(cv);

    Base *b3 = new Sub(b1, b2);
    b2->accept(cv);

    Base *b4 = new Ceiling(b1);
    b4->accept(cv);

    Base *b5 = new Mult(b4, new Op(3));
    b5->accept(cv);

    Base *b6 = new Pow(b3, new Op(2));
    b6->accept(cv);

    EXPECT_EQ(b1->evaluate(), 16.6);
    EXPECT_EQ(b2->evaluate(), 16.6 - 4);
    EXPECT_EQ(b3->evaluate(), 4);
    EXPECT_EQ(b4->evaluate(), 17);
    EXPECT_EQ(b5->evaluate(), 51);
    EXPECT_EQ(b6->evaluate(), 16);

    EXPECT_EQ(cv->add_count(), 1);
    EXPECT_EQ(cv->sub_count(), 2);
    EXPECT_EQ(cv->ceil_count(), 1);
    EXPECT_EQ(cv->mult_count(), 1);
    EXPECT_EQ(cv->pow_count(), 1);

}


#endif
