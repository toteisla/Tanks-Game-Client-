#ifndef _POINT_H_
#define _POINT_H_

#include <stdlib.h>
#include <iostream>

using namespace std;

template <class Type> class Point {
private:
    Type x_;
    Type y_;
public:
    Point() { x_ = 0; y_ = 0;}
    Point(const Type valx, const Type valy);            
    Type getx();
    void setx(const Type valx);
    Type gety();
    void sety(const Type valy);

    Point<Type>& operator=(Point<Type> pt) {
        if (this != &pt) {
            x_ = pt.getx();
            y_ = pt.gety();
        }
        return *this;
    }

};

template <class Type> Point <Type> :: Point(const Type valx, const Type valy) {
    x_ = valx;
    y_ = valy;
}

template <class Type>
Type Point <Type> :: getx() {
    return x_;
}

template <class Type>
void Point <Type> :: setx(const Type valx) {
    x_ = valx;
}

template <class Type>
Type Point <Type> :: gety() {
    return y_;
}

template <class Type>
void Point <Type> :: sety(const Type valy) {
    y_ = valy;
}

template <class Type>
inline bool operator==(const Point <Type>& lhs, const Point <Type>& rhs) { 
    if (lhs.getx() == rhs.getx() && lhs.gety() == rhs.gety()) {
        return true;
    } else {
        return false;
    }
}

template <class Type>
inline bool operator!=(const Point <Type>& lhs, const Point <Type>& rhs) {
    return !operator==(lhs,rhs);
}

#endif

