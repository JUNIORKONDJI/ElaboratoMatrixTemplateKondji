
// KONDJI NGUIMBOUS JUNIOR 7090449

#include "MatrixTemplate.h"

int main() {

    MatrixTemplate<float> A(4, 3);
    A.setValue(1, 1, 2.18);
    A.setValue(1, 2, 1.21);
    A.setValue(1, 3, 4.82);
    A.setValue(2, 1, 1.15);
    A.setValue(2, 2, 3.47);
    A.setValue(2, 3, 8.04);
    A.setValue(3, 1, 4.23);
    A.setValue(3, 2, 2.61);
    A.setValue(3, 3, 5.82);
    A.setValue(4, 1, 3.18);
    A.setValue(4, 2, 5.03);
    A.setValue(4, 3, 6.47);

    A.print();

    MatrixTemplate<float> B(3, 4);
    B.setValue(1, 1, 2.89);
    B.setValue(1, 2, 0.58);
    B.setValue(1, 3, 6.81);
    B.setValue(1, 4, 8.91);
    B.setValue(2, 1, 1.25);
    B.setValue(2, 2, 1.55);
    B.setValue(2, 3, 2.75);
    B.setValue(2, 4, 1.55);
    B.setValue(3, 1, 1.32);
    B.setValue(3, 2, 6.87);
    B.setValue(3, 3, 9.36);
    B.setValue(3, 4, 4.50);

    B.print();

    MatrixTemplate<float> C = A * B;

    C.print();

    MatrixTemplate<float> D = C.transpose();

    D.print();

    MatrixTemplate<float> Drw = D.selectRow(2);

    Drw.print();

    MatrixTemplate<float> Dcl = D.selectColumn(3);

    Dcl.print();

}