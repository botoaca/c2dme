#include "include/MatrixVector.h"

// MatrixVector3

MatrixVector3::MatrixVector3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

MatrixVector3::MatrixVector3(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

std::string MatrixVector3::str() { return "(" + std::to_string(x) + ", " + std::to_string(y) + "," + std::to_string(z) + ")"; } 

MatrixVector3 MatrixVector3::operator+(MatrixVector3& other)
{
    return MatrixVector3{ x + other.x, y + other.y, z + other.z };
}
MatrixVector3 MatrixVector3::operator-(MatrixVector3& other)
{
    return MatrixVector3{ x - other.x, y - other.y, z - other.z };
}
MatrixVector3 MatrixVector3::operator/(int div)
{
    return MatrixVector3{ x / div, y / div, z / div };
}
MatrixVector3 MatrixVector3::operator<<(std::ostream& os)
{
    os << "(" << x << ", " << y << ", " << z << ")";
    return *this;
}
MatrixVector3 MatrixVector3::operator+= (MatrixVector3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}
bool MatrixVector3::operator!=(MatrixVector3& other)
{
    return x != other.x || y != other.y || z != other.z;
}
bool MatrixVector3::operator==(MatrixVector3& other)
{
    return x == other.x && y == other.y && z == other.z;
}

// end MatrixVector3 

// MatrixVector2 

MatrixVector2::MatrixVector2()
{
    this->x = 0;
    this->y = 0;
}

MatrixVector2::MatrixVector2(int x, int y)
{
    this->x = x;
    this->y = y;
}

std::string MatrixVector2::str() { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }

MatrixVector2 MatrixVector2::operator+(MatrixVector2& other)
{
    return MatrixVector2{ x + other.x, y + other.y };
}
MatrixVector2 MatrixVector2::operator-(MatrixVector2& other)
{
    return MatrixVector2{ x - other.x, y - other.y };
}
MatrixVector2 MatrixVector2::operator/(int div)
{
    return MatrixVector2{ x / div, y / div };
}
std::ostream& MatrixVector2::operator<<(std::ostream& os)
{
    os << "(" << x << ", " << y << ")";
    return os;
}
MatrixVector2 MatrixVector2::operator+= (MatrixVector2& other)
{
    x += other.x;
    y += other.y;
    return *this;
}
bool MatrixVector2::operator!=(MatrixVector2& other)
{
    return x != other.x || y != other.y;
}
bool MatrixVector2::operator==(MatrixVector2& other)
{
    return x == other.x && y == other.y;
}

// end MatrixVector2