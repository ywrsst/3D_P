#include <iostream>
#include <cmath>
#include <stdio.h>
#include "MuSoenMath.h"


using namespace std;

void main() {
	mat3 scale(2, 2);             //크기변환행렬 값을 저장해줄 객체
	mat3 rotate(30);              //회전행렬값을 저장해줄 객체
	mat3 translate(3, 5, 1);      //이동행렬 값을 저장해줄 객체
	vec3 v(1,1);                  //기본 벡터값을 저장해줄 객체


	cout << "P =  v * translate * rotate * scale"<<endl;  //17Line 값 출력
	vec3 p = v * translate * rotate * scale;      //operator을 사용해서 p를 계산

	cout << "P = ";

	for (int i = 0; i < 3; i++)
	{
		cout << p.vec[0][i] << " ";
	}

}