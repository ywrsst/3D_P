#pragma once
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

class mat3 {         // mat3 Ŭ���� ����
public:

	float mat[3][3]  // 3x3 ��ı⺻��
	{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	mat3() {}

	mat3(float sz, float sy) {   //ũ�⺯ȯ��� ������(sz , sy)
		mat[0][0] = sz;
		mat[1][1] = sy;
	}

	mat3(float x, float y, float z) { //�̵���ȯ��� ������ (x , y , z)
		mat[2][0] = x;
	    mat[2][1] = y;
		mat[2][2] = z;
    }
	mat3(float rot) { //ȸ����ȯ��� ������(rot)
		mat[0][0] = cos(rot * (3.14 / 180));
		mat[0][1] = -sin(rot * (3.14 / 180));
		mat[1][0] = sin(rot * (3.14 / 180));
		mat[1][1] = cos(rot * (3.14 / 180));
	}
	
};

class vec3 {     // vec3 Ŭ���� ����
public:

	float vec[1][3]   //  3 x 1 ������ �⺻��
	{
		{0,0,1}
	};
	float mt = 0; // ������ ���� mt����
	float mtv[1][3] // ���Ұ��� ������ ����
	{
		{0,0,1}
	};

	vec3(){}

	vec3(float x, float y) { // ��ǥ�� x,y�� ����
		vec[0][0] = x;
		vec[0][1] = y;
}
	vec3 operator *(mat3 m) // ������ �����ε� ����
	{
		for (int i = 0; i < 3; i++) 
		{
			mt = mt + (vec[0][i]) * m.mat[i][0];
		}
		mtv[0][0] = mt;  
		mt = 0;

		for (int i = 0; i < 3; i++)
		{
			mt = mt + (vec[0][i] * m.mat[i][1]);
		}
		mtv[0][1] = mt;
		mt = 0;

		vec[0][0] = mtv[0][0];
		vec[0][1] = mtv[0][1];

		return vec3(vec[0][0], vec[0][1]);   //��ü���� ��ȯ�Ѵ�
	}
	

};
