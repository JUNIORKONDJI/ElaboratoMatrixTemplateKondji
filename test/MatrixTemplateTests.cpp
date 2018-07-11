//
// Created by corso on 11/07/18.
//

#include "gtest/gtest.h"

#include "../MatrixTemplate.h"

TEST(MatrixTemplate, CostruttoreDefault) {

    MatrixTemplate<double> MatA(2, 3);
    ASSERT_EQ(2, MatA.getRow());
    ASSERT_EQ(3, MatA.getColumn());
    ASSERT_EQ(0, MatA.getValue(2, 1));
    MatrixTemplate<double> MatB(1, 6);
    ASSERT_EQ(1, MatB.getRow());

}

TEST(MatrixTemplate, CostruttoreCopia) {

    MatrixTemplate <float> MatA(3, 2);
    MatA.setValue(1, 1, 4.5);
    MatA.setValue(1, 2, 9.1);
    MatA.setValue(2, 1, 4);
    MatA.setValue(2, 2, 7.8);
    MatA.setValue(3, 1, 1.6);
    MatA.setValue(3, 2, 8.2);
    MatrixTemplate<float> MatB(MatA);
    ASSERT_TRUE(MatA== MatB);
    MatB.setValue(1, 1, 7.1);
    ASSERT_FALSE(MatA== MatB);

}

TEST(MatrixTemplate, OperatoreSommaUguale) {

    MatrixTemplate<long int> MatA(3, 3);
    MatA.setValue(1, 1, 10);
    MatA.setValue(1, 2, 7);
    MatA.setValue(1, 3, 3);
    MatA.setValue(2, 1, 9);
    MatA.setValue(2, 2, 2);
    MatA.setValue(2, 3, 1);
    MatA.setValue(3, 1, 5);
    MatA.setValue(3, 2, 9);
    MatA.setValue(3, 3, 3);
    MatrixTemplate<long int> MatB(3, 3);
    MatB.setValue(1, 2, 3);
    MatB.setValue(2, 2, 4);
    MatB.setValue(2, 3, 1);
    MatB.setValue(3, 1, 5);

    MatA+= MatB;

    ASSERT_EQ(10,MatA.getValue(1, 2));
    ASSERT_EQ(6,MatA.getValue(2, 2));
    ASSERT_EQ(2,MatA.getValue(2, 3));
    ASSERT_EQ(10,MatA.getValue(3, 1));
    ASSERT_ANY_THROW(MatA.setValue(1, 4, 2));

}

TEST(MatrixTemplate, OperatoreSomma) {

    MatrixTemplate<int> MatA(3,3);
    MatA.setValue(1 ,1, 4);
    MatA.setValue(1, 2, 5);
    MatA.setValue(1, 3, 1);
    MatA.setValue(2, 1, 8);
    MatA.setValue(2, 2, 13);
    MatA.setValue(2, 3, 6);
    MatA.setValue(3, 1, 3);
    MatA.setValue(3, 2, 2);
    MatA.setValue(3, 3, 12);
    MatrixTemplate<int> MatB(3, 4);
    MatrixTemplate<int> MatC(3, 3);
    MatC.setValue(1, 1, 3);
    MatC.setValue(2, 1, 4);
    MatC.setValue(3, 1, 1);
    MatC.setValue(3, 2, 5);
    MatC.setValue(3, 3, 4);
    MatrixTemplate<int> MatD(1, 1);

    MatD= MatA+ MatC;

    ASSERT_EQ(7, MatD.getValue(1, 1));
    ASSERT_EQ(12, MatD.getValue(2, 1));
    ASSERT_EQ(4, MatD.getValue(3, 1));
    ASSERT_EQ(7, MatD.getValue(3, 2));
    ASSERT_EQ(16, MatD.getValue(3, 3));
    ASSERT_ANY_THROW(MatA+ MatB);

}

TEST(MatrixTemplate, OperatoreUguale_Diverso) {

    MatrixTemplate<float> MatA(2, 2);
    MatA.setValue(1, 1, 2.8);
    MatA.setValue(1, 2, 4);
    MatA.setValue(2, 1, 12);
    MatA.setValue(2, 2, 9.8);
    MatrixTemplate<float> MatB(2, 2);
    MatB.setValue(1, 1, 2.8);
    MatB.setValue(1, 2, 4);
    MatB.setValue(2, 1, 12);
    MatB.setValue(2, 2, 9.8);

    ASSERT_TRUE(MatA== MatB);
    ASSERT_FALSE(MatA!= MatB);

    MatA.setValue(1, 1, 2);

    ASSERT_TRUE(MatA!= MatB);
    ASSERT_FALSE(MatA== MatB);

}