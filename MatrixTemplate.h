//
// KONDJI NGUIMBOUS JUNIOR 7090449.
//

#ifndef MATRIXTEMPLATE_MATRIXTEMPLATE_H
#define MATRIXTEMPLATE_MATRIXTEMPLATE_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cfloat>
#include "UtilsMatrixTemplate.h"

template<typename T>
class MatrixTemplate {
public:
    MatrixTemplate(int lenVect, bool normalVect) {

        if (lenVect < 1)
            lenVect = 1;
        if (normalVect){
            //vettore colonna
            rows = lenVect;
            columns = 1;
        }else{
            rows = 1;
            columns= lenVect;
        }
        buffer = new T[rows * columns];
        for(int i = 0; i < rows*columns;++i) {
            buffer[i] = 0;
        }
    }

    ~MatrixTemplate() {

        delete[] buffer;

    }

    MatrixTemplate(const MatrixTemplate &rh) {

        rows = rh.rows;
        columns = rh.columns;
        buffer = new T[rows * columns];
        /*for (int i = 0; i < rows * columns; i++)
            buffer[i] = rh.buffer[i];*/
        memcpy(buffer,rh.buffer,rows*columns*sizeof (buffer[0]));

    }

    MatrixTemplate &operator=(const MatrixTemplate &rh) {

        if (&rh == this)
            return *this;
        rows = rh.rows;
        columns = rh.columns;
        delete[]buffer;
        buffer = new T[rows * columns];
        /*for (int i = 0; i < rows * columns; i++)
            buffer[i] = rh.buffer[i];*/

        mempcpy(buffer,rh.buffer,rows*columns*sizeof (buffer[0]));
        return *this;

    }




    MatrixTemplate &operator+=(const MatrixTemplate &rh) {

        if (rows!=rh.rows || columns!=rh.columns)
            throw std::logic_error(
                    "Nella somma, le righe e le colonne degli addendi devono avere la stessa dimensione");
        for (int i = 0; i < rows * columns; i++)
            buffer[i] = buffer[i] + rh.buffer[i];
        return *this;

    }

    MatrixTemplate operator+(const MatrixTemplate &rh) const {

        if (rows != rh.rows || columns != rh.columns)
            throw std::logic_error(
                    "Nella somma, le righe e le colonne degli addendi devono avere la stessa dimensione");
        MatrixTemplate<T> tmp(rows, columns);
        for (int i = 0; i < rh.rows * rh.columns; i++)
            tmp.buffer[i] = buffer[i] + rh.buffer[i];
        return tmp;

    }

    MatrixTemplate operator*(const MatrixTemplate &rh) const {

        if (columns != rh.rows)
            throw std::logic_error(
                    "Nel prodotto, le colonne del primo e le righe del secondo fattore devono avere stessa dimensione");
        MatrixTemplate<T> tmp(rows, rh.columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rh.columns; j++) {
                tmp.buffer[i * rh.columns + j] = 0;
                for (int h = 0; h < columns; h++)
                    tmp.buffer[i * rh.columns + j] += buffer[i * columns + h] * rh.buffer[h * rh.columns + j];
            }
        return tmp;

    }

    MatrixTemplate operator*(const T& rh) const {

        MatrixTemplate<T> retMatrix(rows,columns);
        for(int i=0; i<rows*columns;i++)
            retMatrix.buffer[i]=rh*buffer[i];
        return retMatrix;

    }


    bool operator==(const MatrixTemplate &rh) const {

        if (rows != rh.rows || columns != rh.columns)
            return false;
        for (int i = 0; i < rows * columns; i++) {
            if (!isEqual(buffer[i],rh.buffer[i]))
                return false;
        }
        return true;

    }

    bool operator!=(const MatrixTemplate& rh)const {

        return !(*this==rh);

    }


    MatrixTemplate transpose() const {

        MatrixTemplate<T> tmp(columns, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                tmp.buffer[tmp.columns * j + i] = buffer[columns * i + j];
        return tmp;

    }


    void print() {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << buffer[columns * (i) + j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

    }

    T getValue(int i, int j) const {

        if (i > rows|| i<1 || j<1  || j > columns)
            throw std::out_of_range("Elemento non presente nella matrice");
        return buffer[columns * (i - 1) + j - 1];

    }

    void setValue(int i, int j, const T &value) const {

        if (i > rows || j > columns)
            throw std::out_of_range("Elemento non presente nella matrice");
        buffer[columns * (i - 1) + j - 1] = value;

    }

    MatrixTemplate selectRow(int i) {

        if (i > rows || i<1)
            throw std::out_of_range("Riga non presente nella matrice");
        MatrixTemplate<T> tmp(1, columns);
        for (int j = 0; j < columns; j++)
            tmp.buffer[j] = buffer[columns * (i - 1) + j];
        return tmp;

    }

    MatrixTemplate selectColumn(int j) {

        if (j > rows || j<1)
            throw std::out_of_range("Colonna non presente nella matrice");
        MatrixTemplate<T> tmp(rows, 1);
        for (int i = 0; i < rows; i++)
            tmp.buffer[i] = buffer[j - 1 + columns * i];
        return tmp;

    }

    int getRow() const{

        return rows;

    }

    int getColumn() const{

        return columns;

    }


private:

    int rows, columns;
    T *buffer;

};


#endif //MATRIXTEMPLATE_MATRIXTEMPLATE_H
