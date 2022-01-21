#pragma once
#include "Utility.h"

class MatrixVector3
{   
    public:
        MatrixVector3();
        MatrixVector3(int x, int y, int z);

        int x, y, z;
        std::string str();

        MatrixVector3 operator+(MatrixVector3& other);
        MatrixVector3 operator-(MatrixVector3& other);
        MatrixVector3 operator/(int div);
        MatrixVector3 operator<<(std::ostream& os);
        MatrixVector3 operator+=(MatrixVector3& other);
        bool operator!=(MatrixVector3& other);
        bool operator==(MatrixVector3& other);
};
typedef MatrixVector3 RGB;
class MatrixVector2
{
    public:
        MatrixVector2();
        MatrixVector2(int x, int y);
        
        int x, y;
        std::string str();
        
        MatrixVector2 operator+(MatrixVector2& other);
        MatrixVector2 operator-(MatrixVector2& other);
        MatrixVector2 operator/(int div);
        std::ostream& operator<<(std::ostream& os);
        MatrixVector2 operator+=(MatrixVector2& other);
        bool operator!=(MatrixVector2& other);
        bool operator==(MatrixVector2& other);
};
