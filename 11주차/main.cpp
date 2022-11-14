#include <iostream>
#include <cmath>
#include <stdio.h>
#include "MuSoenMath.h"


using namespace std;
using namespace LJM;

void main() {
	mat3 scale(2, 2);             //크기변환행렬 값을 저장해줄 객체
	mat3 rotate(30);              //회전행렬값을 저장해줄 객체
	mat3 translate(3, 5, 1);      //이동행렬 값을 저장해줄 객체
	               


	vec33 vv(2, 3, 4);
	vec4  v4(1, 2, 3, 4);
	vec4  vp4(1, 2, 3, 4);

	matrix4 transmat4(1, 2, 3, 4);

	mat3 mat(1, 1, 1, 2, 2, 2, 3, 3, 3);
	mat3 matt(1, 2, 3, 1, 2, 3, 1, 2, 3);

	matrix4 mat4(1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4);
	matrix4 mat44(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

	mat3 mtt3 = mat * matt;
	mat3 mtp3 = mat + matt;
	mat3 mtm3 = mat - matt;

	matrix4 matt4 = mat4 * mat44;
	matrix4 matp4 = mat4 + mat44;
	matrix4 matm4 = mat4 - mat44;


	vec3 v(1, 2, 3 );
	vec3 pp = v * mat;

	vec4 v44(1, 2, 3, 4);
	vec4 ppp = v44 * mat4;

	vec44 vv4(1, 2, 3, 4);

	


	cout << "P =  v * translate * rotate * scale" << endl;  //17Line 값 출력
	vec3 p = v * translate * rotate * scale;      //operator을 사용해서 p를 계산

	cout << "P = ";

	for (int i = 0; i < 3; i++)
	{
		cout << p.vec[0][i] << " ";

	}

	cout << "\n" << endl;
	cout << "translate 행렬" << endl;      //translate 행렬 출력

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << translate.mat[j][i]<<" ";
		}
		cout << endl;
	}



	cout << "\n" << endl;                     
	cout << "translate 전치상태" << endl;   //전치 행렬 출력
	                                       //단위 행렬이 초기값으로 초기화 한 후의 수 이기때문에 전치부터 해준다.
	translate.tm();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << translate.mat[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "\n" << endl;
	cout << "translate단위 행렬" << endl;           //단위 행렬 출력
	
	translate.im();                       //MuSoenMath.h에서 선언한 im를 translate에서 단위행렬로 초기화
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << translate.mat[j][i] << " ";
		}
		cout << endl;
	}

	cout << "★★★★★★★★★★★★★★★-4x4 행렬-★★★★★★★★★★★★★★★★★ \n" << endl;
	cout << "4x4 행렬" << endl;   									   
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << transmat4.mat4[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "4x4 전치상태 " << endl;
	transmat4.tm4();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << transmat4.mat4[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "4x4 단위행렬" << endl;
	transmat4.im4();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << transmat4.mat4[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "★★★★★★★★★★★★★★★-1x3 벡터-★★★★★★★★★★★★★★★★★ \n" << endl;
	
	for (int i = 0; i < 3; i++)
	{
		cout << vv.vec[0][i] << "   ";
	}
	cout << endl;
	cout << endl;

	cout << "--1x3 벡터 전치--" << endl;
	vv.ttransvec33();

	for (int i = 0; i < 3; i++)
	{
		cout << vv.vec[i][0] << endl;
	}
	cout << endl;

	cout << "--1x3 단위 벡터--" << endl;
	vv.idvec3();
	for (int i = 0; i < 3; i++)
	{
		cout << vv.vec[0][i] << "   ";
	}
	cout << endl << endl;

	cout << "--3x1 단위 벡터--" << endl;
	vv.idvec3();
	for (int i = 0; i < 3; i++)
	{
		cout << vv.vec[i][0] << endl;
	}

	cout << "★★★★★★★★★★★★★★★-1x4 벡터-★★★★★★★★★★★★★★★★★ \n" << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << vp4.vec1[0][i] << "  ";
	}
	cout << endl; 
	cout << endl;

	cout << "--1x4 벡터 전치--" << endl;
	v4.transvec4();
	for (int i = 0; i < 4; i++)
	{
		cout << vp4.vec1[0][i] << endl;
	}

	cout << endl;
	cout << "--1x4 단위 벡터--" << endl;
	v4.iv4();
	for (int i = 0; i < 4; i++)
	{
		cout << v4.vec1[0][i] << "  ";
	}
	cout << endl << endl;

	cout << "--4x1 단위 벡터--" << endl;
	v4.iv4();
	for (int i = 0; i < 4; i++)
	{
		cout << v4.mtv4[i][0] << endl;
	}
	
	cout << "★★★★★★★★★★★★★-3x3행렬 X 행렬 곱셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1, 1, 1}" << endl << "{2, 2, 2}" << endl << "{3, 3, 3}" << endl
		<< "곱하기" << endl << "{1, 2, 3}" << endl << "{1, 2, 3}" << endl << "{1, 2, 3}" << endl
		<< "=" << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mtt3.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}

	cout << "★★★★★★★★★★★★★-4x4행렬 X 행렬 곱셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1, 1, 1, 1}" << endl << "{2, 2, 2, 2}" << endl << "{3, 3, 3, 3}" << endl <<"{4, 4, 4, 4}"
		<< endl << "곱하기" << endl << "{1, 2, 3, 4}" << endl << "{1, 2, 3, 4}" << endl << "{1, 2, 3, 4}" << endl
		<<"{1, 2, 3, 4}"<< endl << "=" << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matt4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << "★★★★★★★★★★★★★-33전치행렬 X 행렬 곱셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << "<-------33배열 전치상태" << endl << "곱하기" 
		 << endl << "{1,2,3}" << endl << "{1,2,3}" << endl << "{1,2,3}" << endl << "=" << endl;
	
	mat.tm();
	mtt3 = mat * matt;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mtt3.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "★★★★★★★★★★★★★-44전치행렬 X 행렬 곱셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}"<<"<-------44배열 전치상태" 
		 << endl << "곱하기" << endl << "{1,2,3,4}" << endl << "{1,2,3,4}" << endl << "{1,2,3,4}" << endl 
		<< "{1,2,3,4}" << endl << "=" << endl;

	mat4.tm4();
	matt4 = mat4 * mat44;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matt4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "★★★★★★★★★★★★★-3 3행렬 1 3벡터 곱셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl << "곱하기" 
		 << endl << "{1,2,3}" << endl << "=" << endl;
	cout << pp.vec[0][0] << " ";
	cout << pp.vec[0][1] << " ";
	cout << pp.vec[0][2] << endl << endl;

	cout << "★★★★★★★★★★★★★-4 4행렬 1 4벡터 곱셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}"
		 << endl << "곱하기" << endl << "{1,2,3,4}" << endl << "=" << endl;
	cout << ppp.vec1[0][0] << " ";
	cout << ppp.vec1[0][1] << " ";
	cout << ppp.vec1[0][2] << " ";
	cout << ppp.vec1[0][3] << endl << endl;

	cout << "★★★★★★★★★★★★★-3 3행렬 1 3전치벡터 곱셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl 
		<< "곱하기" << endl << "{2,3,4}" << "<------벡터 전치했을 경우" << endl << "=" << endl;
	vv.vec[0][0] = 2;
	vv.vec[0][1] = 3;
	vv.vec[0][2] = 4;
	vv.ttransvec33();
	mat.tm();
	vec33 tvec3 = vv * mat;

	cout << vv.vec[0][0] << " ";
	cout << vv.vec[1][0] << " ";
	cout << vv.vec[2][0] << endl << endl;

	cout << "★★★★★★★★★★★★★-4 4행렬 1 4전치벡터 곱셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}" << endl 
		<< "곱하기" << endl << "{1,2,3,4}" << "<------벡터 전치했을 경우" << endl << "=" << endl;
	vv4.vec[0][0] = 1;
	vv4.vec[0][1] = 2;
	vv4.vec[0][2] = 3;
	vv4.vec[0][3] = 4;
	vv4.ttransvec44();
	mat4.tm4();
	vec44 tvec4 = vv4 * mat4;

	cout << vv4.vec41[0][0] << "  ";
	cout << vv4.vec41[1][0] << "  ";
	cout << vv4.vec41[2][0] << "  ";
	cout << vv4.vec41[3][0] << endl << endl;

	cout << "★★★★★★★★★★★★★-3x3 행렬간 덧셈, 뺄셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl << "더하기" << endl << "{1,2,3}" 
		<< endl << "{1,2,3}" << endl << "{1,2,3}" << endl << "=" << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mtp3.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl << "빼기" << endl
		<< "{1,2,3}" << endl << "{1,2,3}" << endl << "{1,2,3}" << endl << "=" << endl;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mtm3.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "★★★★★★★★★★★★★-4x4 행렬간 덧셈, 뺄셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}" << endl << "더하기" 
		<< endl << "{1,2,3,4}" << endl << "{1,2,3,4}" << endl << "{1,2,3,4}" << endl 
		<< "{1,2,3,4}" << endl << "=" << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matp4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}" <<  endl 
		 << "빼기" << endl << "{1,2,3,4}" << endl << "{1,2,3,4}" << endl <<
		"{1,2,3,4}" << endl << "{1,2,3,4}" << endl << "=" << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matm4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "★★★★★★★★★★★★★-33 행렬 상수곱-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl << "곱하기" 
		 << endl << "3" << endl << "결과값은?" << endl;
	
	mat.cmtmat3(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mat.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "★★★★★★★★★★★★★-44 행렬 상수곱-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}" 
		 << endl << endl << "곱하기" << endl << "4" << endl << "=" << endl;
	mat4.ctmt4(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << mat4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "★★★★★★★★★★★★★-33 행렬 상수나눗셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{3,3,3}" << endl << "{6,6,6}" << endl 
		 << "{9,9,9}" << endl << "나누기" << endl << "3" << endl << "=" << endl;
	mat.cdvmat3(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mat.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "★★★★★★★★★★★★★-44 행렬 상수나눗셈-★★★★★★★★★★★★★★★ \n" << endl;
	cout << "{2,2,2,2}" << endl << "{4,4,4,4}" << endl << "{6,6,6,6}" << endl 
		 << "{8,8,8,8}" << endl << endl << "나누기" << endl << "2" << endl << "=" << endl;
	mat4.ctds4(2);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << mat4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "★★★★★★★★★★★★★-13벡터 상수곱-★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,2,3}" << endl << endl << "곱하기" << endl << "3" << endl << "=" << endl;
	v.vec[0][0] = 1; v.vec[0][1] = 2; v.vec[0][2] = 3;
	v.cmtvec3(3);

	cout << v.vec[0][0] << " ";
	cout << v.vec[0][1] << " ";
	cout << v.vec[0][2] << " ";
	cout << endl;

	cout << "★★★★★★★★★★★★★-14벡터 상수곱-★★★★★★★★★★★★★★ \n" << endl;
	cout << "{1,2,3,4}" << endl << endl << "곱하기" << endl << "4" << endl << "=" << endl;
	v4.vec1[0][0] = 1; v4.vec1[0][1] = 2; v4.vec1[0][2] = 3; v4.vec1[0][3] = 4;
	v4.cmtvec4(4);

	cout << v4.vec1[0][0] << " ";
	cout << v4.vec1[0][1] << " ";
	cout << v4.vec1[0][2] << " ";
	cout << v4.vec1[0][3] << " ";
	cout << endl;

	cout << "★★★★★★★★★★★★★-13벡터 상수나눗셈-★★★★★★★★★★★★★★ \n" << endl;
	cout << "{2,4,6}" << endl << endl << "나누기" << endl << "2" << endl << "=" << endl;
	v.vec[0][0] = 2; v.vec[0][1] = 4; v.vec[0][2] = 6;
	v.cdvvec3(2);

	cout << v.vec[0][0] << " ";
	cout << v.vec[0][1] << " ";
	cout << v.vec[0][2];
	cout << endl;

	cout << "★★★★★★★★★★★★★-14벡터 상수나눗셈-★★★★★★★★★★★★★★ \n" << endl;
	cout << "{2,4,6,8}" << endl << endl << "나누기" << endl << "2" << endl << "=" << endl;
	v4.vec1[0][0] = 2; v4.vec1[0][1] = 4; v4.vec1[0][2] = 6; v4.vec1[0][3] = 8;
	v4.cdvvec4(2);

	cout << v4.vec1[0][0] << "  ";
	cout << v4.vec1[0][1] << "  ";
	cout << v4.vec1[0][2] << "  ";
	cout << v4.vec1[0][3] << "  ";
	cout << endl;
};