#include <iostream>
#include <cmath>
#include <stdio.h>
#include "MuSoenMath.h"


using namespace std;

void main() {
	mat3 scale(2, 2);             //ũ�⺯ȯ��� ���� �������� ��ü
	mat3 rotate(30);              //ȸ����İ��� �������� ��ü
	mat3 translate(3, 5, 1);      //�̵���� ���� �������� ��ü
	vec3 v(1,1);                  //�⺻ ���Ͱ��� �������� ��ü


	cout << "P =  v * translate * rotate * scale"<<endl;  //17Line �� ���
	vec3 p = v * translate * rotate * scale;      //operator�� ����ؼ� p�� ���

	cout << "P = ";

	for (int i = 0; i < 3; i++)
	{
		cout << p.vec[0][i] << " ";
	}

}