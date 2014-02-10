#include "StdAfx.h"
#include "Vector.h"
#include "math.h"

Vector::Vector(double a, double b)
{
    x=a;
    y=b;
}

Vector::~Vector(void)
{
}

void Vector::add(Vector& v){
    x+=v.x;
    y+=v.y;
}

void Vector::rotate(double angle){// angle in degrees
	angle=angle/360.0*2*3.141;// convert to radians

	double a,b;

	a= x*cos(angle)+y*sin(angle);
	b= x*-sin(angle)+y*cos(angle);

	x=a;
	y=b;

}
