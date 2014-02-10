#pragma once

class Vector
{
public: 
    double x,y;
  
	Vector(double=0.0,double=0.0);
    void add(Vector& v);
	void rotate(double angle);
	void scale(float f){x*=f;y*=f;};
	double dot(Vector &v){return x*v.x+y*v.y;};

public:
    ~Vector(void);
};
