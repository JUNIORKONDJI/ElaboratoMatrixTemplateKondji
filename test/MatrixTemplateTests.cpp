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
    MatrixTemplate<long int> MatC(3, 3);
    MatB.setValue(1, 2, 3);
    MatB.setValue(2, 2, 4);
    MatB.setValue(2, 3, 1);
    MatB.setValue(3, 1, 5);
    MatC.setValue(1, 2, 3);
    MatC.setValue(2, 2, 4);
    MatC.setValue(2, 3, 1);
    MatC.setValue(3, 1, 5);

    MatA+= MatB+ MatC;

    ASSERT_EQ(13,MatA.getValue(1, 2));
    ASSERT_EQ(10,MatA.getValue(2, 2));
    ASSERT_EQ(3,MatA.getValue(2, 3));
    ASSERT_EQ(15,MatA.getValue(3, 1));
    ASSERT_THROW(MatA.setValue(1, 4, 2), std::logic_error);

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
    MatrixTemplate<int> MatE(3, 3);
    MatC.setValue(1, 1, 3);
    MatC.setValue(2, 1, 4);
    MatC.setValue(3, 1, 1);
    MatC.setValue(3, 2, 5);
    MatC.setValue(3, 3, 4);
    MatE.setValue(1, 1, 3);
    MatE.setValue(2, 1, 4);
    MatE.setValue(3, 1, 1);
    MatE.setValue(3, 2, 5);
    MatE.setValue(3, 3, 4);
    MatrixTemplate<int> MatD(1, 1);

    MatD= MatA+ MatC+ MatE;

    ASSERT_EQ(10, MatD.getValue(1, 1));
    ASSERT_EQ(16, MatD.getValue(2, 1));
    ASSERT_EQ(5, MatD.getValue(3, 1));
    ASSERT_EQ(12, MatD.getValue(3, 2));
    ASSERT_EQ(20, MatD.getValue(3, 3));
    ASSERT_THROW(MatA+ MatB, std::logic_error);

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

TEST(MatrixTemplate, OperatoreMoltiplicazione) {

    MatrixTemplate<int> A(2, 3);
    A.setValue(1, 1, 2);
    A.setValue(1, 2, 3);
    A.setValue(1, 3, 5);
    A.setValue(2, 1, 4);
    A.setValue(2, 2, 7);
    A.setValue(2, 3, 1);
    MatrixTemplate<int> B(2, 3);
    ASSERT_THROW(A* B, std::logic_error);
    MatrixTemplate<int> C(3, 2);
    MatrixTemplate<int> E(2, 2);
    C.setValue(1, 1, 1);
    C.setValue(1, 2, 5);
    C.setValue(2, 1, 6);
    C.setValue(2, 2, 9);
    C.setValue(3, 1, 2);
    C.setValue(3, 2, 8);
    E.setValue(1, 1, 1);
    E.setValue(1, 2, 5);
    E.setValue(2, 1, 6);
    E.setValue(2, 2, 9);
    MatrixTemplate<int> D(2, 2);
    D= A* C * E;
    ASSERT_EQ(D.getValue(1, 1), 492);
    ASSERT_EQ(D.getValue(1, 2), 843);
    ASSERT_EQ(D.getValue(2, 1), 594);
    ASSERT_EQ(D.getValue(2, 2), 1059);
    C= C* 4;
    ASSERT_EQ(C.getValue(1, 1), 4);
    ASSERT_EQ(C.getValue(1, 2), 20);
    ASSERT_EQ(C.getValue(2, 1), 24);
    ASSERT_EQ(C.getValue(3, 2), 32);

}

TEST(MatrixTemplate, SelezioneRiga) {

    MatrixTemplate<long int> MatA(3, 3);
    MatA.setValue(1, 1, 5);
    MatA.setValue(1, 2, 2);
    MatA.setValue(1, 3, 7);
    MatA.setValue(2, 1, 4);
    MatA.setValue(2, 2, 1);
    MatA.setValue(2, 3, 8);
    MatA.setValue(3, 1, 2);
    MatA.setValue(3, 2, 0);
    MatA.setValue(3, 3, 3);
    MatrixTemplate<long int> MatB(MatA.selectRow(2));
    ASSERT_EQ(4, MatB.getValue(1, 1));
    ASSERT_EQ(1, MatB.getValue(1, 2));
    ASSERT_EQ(8, MatB.getValue(1, 3));
    ASSERT_THROW(MatA.selectRow(7), std::out_of_range);

}

TEST(MatrixTemplate, SelezioneColonna) {

    MatrixTemplate<int> MatA(3, 3);
    MatA.setValue(1, 1, 2);
    MatA.setValue(1, 2, 4);
    MatA.setValue(1, 3, 8);
    MatA.setValue(2, 1, 0);
    MatA.setValue(2, 2, 4);
    MatA.setValue(2, 3, 8);
    MatA.setValue(3, 1, 0);
    MatA.setValue(3, 2, 1);
    MatA.setValue(3, 3, 5);
    MatrixTemplate<int> MatB(MatA.selectColumn(3));
    ASSERT_EQ(8, MatB.getValue(1, 1));
    ASSERT_EQ(8, MatB.getValue(2, 1));
    ASSERT_EQ(5, MatB.getValue(3, 1));
    ASSERT_THROW(MatA.selectColumn(7), std::out_of_range);

}

TEST(MatrixTemplate, SettareValore) {

    MatrixTemplate<double> MatA(3, 3);
    MatA.setValue(1, 1, 6);
    MatA.setValue(1, 2, 7);
    MatA.setValue(1, 3, 1);
    MatA.setValue(2, 1, 4);
    MatA.setValue(2, 2, 5);
    MatA.setValue(2, 3, 0);
    MatA.setValue(3, 1, 2);
    MatA.setValue(3, 2, 9);
    MatA.setValue(3, 3, 2);
    ASSERT_THROW(MatA.setValue(3, 5, 9), std::out_of_range);

}

TEST(MatrixTemplate, PrendereValore) {

    MatrixTemplate<short int> MatA(3, 3);
    MatA.setValue(1, 1, 2);
    MatA.setValue(1, 2, 8);
    MatA.setValue(1, 3, 3);
    MatA.setValue(2, 1, 9);
    MatA.setValue(2, 2, 2);
    MatA.setValue(2, 3, 6);
    MatA.setValue(3, 1, 1);
    MatA.setValue(3, 2, 5);
    MatA.setValue(3, 3, 0);
    ASSERT_EQ(6, MatA.getValue(2, 3));
    ASSERT_EQ(0, MatA.getValue(3, 3));
    ASSERT_THROW(MatA.getValue(5, 3), std::out_of_range);

}

TEST(MatrixTemplate,Transpose) {
    MatrixTemplate<double> MatA(2, 3);
    MatA.setValue(1, 1, 7);
    MatA.setValue(1, 2, 0);
    MatA.setValue(1, 3, 4);
    MatA.setValue(2, 1, 1);
    MatA.setValue(2, 2, 5);
    MatA.setValue(2, 3, 3);
    MatrixTemplate<double> MatB(MatA.transpose());
    ASSERT_EQ(3, MatB.getRow());
    ASSERT_EQ(2, MatB.getColumn());
    ASSERT_EQ(3, MatB.getValue(3, 2));
    ASSERT_EQ(0, MatB.getValue(2, 1));
    ASSERT_EQ(5, MatB.getValue(2, 2));

}
