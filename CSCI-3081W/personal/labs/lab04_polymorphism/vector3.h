#ifndef VECTOR3_H_
#define VECTOR3_H_

class Vector3 {
public:
	float x;
	float y;
	float z;
public:
	Vector3();
	Vector3(float x, float y, float z);
	void Print();
	Vector3 operator+(Vector3 vec);
	Vector3 operator-(Vector3 vec);
	Vector3 operator*(float scal);
	Vector3 operator/(float scal);
};

#endif
