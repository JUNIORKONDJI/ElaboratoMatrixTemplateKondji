//
// Created by corso on 11/07/18.
//

#include "gtest/gtest.h"

#include "../MatrixTemplate.h"

TEST(MatrixTemplate, CostruttoreDefault){

    MatrixTemplate<double> MatA(2, 3);
    ASSERT_EQ(2, MatA.getRow());
    ASSERT_EQ(4, MatA.getColumn());
    ASSERT_EQ(0, MatA.getValue(2, 1));
    MatrixTemplate<double> MatB(1, 6);
    ASSERT_EQ(1, MatB.getRow());

}


TEST(MatrixTemplate, CostruttoreCopia){

    MatrixTemplate <float> MatA(3, 2);
    MatA.setValue(1, 1, 4.5);
    MatA.setValue(1, 2, 9.1);
    MatA.setValue(2, 1, 4);
    MatA.setValue(2, 2, 7.8);
    MatA.setValue(3, 1, 1.6);
    MatA.setValue(3, 2, 8.2);
    MatrixTemplate<float> MatB(MatA);
    ASSERT_TRUE(MatA==MatB);
    MatB.setValue(1, 1, 7.1);
    ASSERT_FALSE(MatA==MatB);

}