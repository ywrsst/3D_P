#include <iostream>
#include <cmath>
#include <stdio.h>
#include "MuSoenMath.h"


using namespace std;
using namespace LJM;

void main() {
	mat3 scale(2, 2);             //ũ�⺯ȯ��� ���� �������� ��ü
	mat3 rotate(30);              //ȸ����İ��� �������� ��ü
	mat3 translate(3, 5, 1);      //�̵���� ���� �������� ��ü
	               


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

	


	cout << "P =  v * translate * rotate * scale" << endl;  //17Line �� ���
	vec3 p = v * translate * rotate * scale;      //operator�� ����ؼ� p�� ���

	cout << "P = ";

	for (int i = 0; i < 3; i++)
	{
		cout << p.vec[0][i] << " ";

	}

	cout << "\n" << endl;
	cout << "translate ���" << endl;      //translate ��� ���

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << translate.mat[j][i]<<" ";
		}
		cout << endl;
	}



	cout << "\n" << endl;                     
	cout << "translate ��ġ����" << endl;   //��ġ ��� ���
	                                       //���� ����� �ʱⰪ���� �ʱ�ȭ �� ���� �� �̱⶧���� ��ġ���� ���ش�.
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
	cout << "translate���� ���" << endl;           //���� ��� ���
	
	translate.im();                       //MuSoenMath.h���� ������ im�� translate���� ������ķ� �ʱ�ȭ
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << translate.mat[j][i] << " ";
		}
		cout << endl;
	}

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�-4x4 ���-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "4x4 ���" << endl;   									   
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << transmat4.mat4[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "4x4 ��ġ���� " << endl;
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

	cout << "4x4 �������" << endl;
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

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�-1x3 ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	
	for (int i = 0; i < 3; i++)
	{
		cout << vv.vec[0][i] << "   ";
	}
	cout << endl;
	cout << endl;

	cout << "--1x3 ���� ��ġ--" << endl;
	vv.ttransvec33();

	for (int i = 0; i < 3; i++)
	{
		cout << vv.vec[i][0] << endl;
	}
	cout << endl;

	cout << "--1x3 ���� ����--" << endl;
	vv.idvec3();
	for (int i = 0; i < 3; i++)
	{
		cout << vv.vec[0][i] << "   ";
	}
	cout << endl << endl;

	cout << "--3x1 ���� ����--" << endl;
	vv.idvec3();
	for (int i = 0; i < 3; i++)
	{
		cout << vv.vec[i][0] << endl;
	}

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�-1x4 ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << vp4.vec1[0][i] << "  ";
	}
	cout << endl; 
	cout << endl;

	cout << "--1x4 ���� ��ġ--" << endl;
	v4.transvec4();
	for (int i = 0; i < 4; i++)
	{
		cout << vp4.vec1[0][i] << endl;
	}

	cout << endl;
	cout << "--1x4 ���� ����--" << endl;
	v4.iv4();
	for (int i = 0; i < 4; i++)
	{
		cout << v4.vec1[0][i] << "  ";
	}
	cout << endl << endl;

	cout << "--4x1 ���� ����--" << endl;
	v4.iv4();
	for (int i = 0; i < 4; i++)
	{
		cout << v4.mtv4[i][0] << endl;
	}
	
	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-3x3��� X ��� ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1, 1, 1}" << endl << "{2, 2, 2}" << endl << "{3, 3, 3}" << endl
		<< "���ϱ�" << endl << "{1, 2, 3}" << endl << "{1, 2, 3}" << endl << "{1, 2, 3}" << endl
		<< "=" << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mtt3.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-4x4��� X ��� ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1, 1, 1, 1}" << endl << "{2, 2, 2, 2}" << endl << "{3, 3, 3, 3}" << endl <<"{4, 4, 4, 4}"
		<< endl << "���ϱ�" << endl << "{1, 2, 3, 4}" << endl << "{1, 2, 3, 4}" << endl << "{1, 2, 3, 4}" << endl
		<<"{1, 2, 3, 4}"<< endl << "=" << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matt4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-33��ġ��� X ��� ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << "<-------33�迭 ��ġ����" << endl << "���ϱ�" 
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

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-44��ġ��� X ��� ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}"<<"<-------44�迭 ��ġ����" 
		 << endl << "���ϱ�" << endl << "{1,2,3,4}" << endl << "{1,2,3,4}" << endl << "{1,2,3,4}" << endl 
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

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-3 3��� 1 3���� ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl << "���ϱ�" 
		 << endl << "{1,2,3}" << endl << "=" << endl;
	cout << pp.vec[0][0] << " ";
	cout << pp.vec[0][1] << " ";
	cout << pp.vec[0][2] << endl << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-4 4��� 1 4���� ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}"
		 << endl << "���ϱ�" << endl << "{1,2,3,4}" << endl << "=" << endl;
	cout << ppp.vec1[0][0] << " ";
	cout << ppp.vec1[0][1] << " ";
	cout << ppp.vec1[0][2] << " ";
	cout << ppp.vec1[0][3] << endl << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-3 3��� 1 3��ġ���� ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl 
		<< "���ϱ�" << endl << "{2,3,4}" << "<------���� ��ġ���� ���" << endl << "=" << endl;
	vv.vec[0][0] = 2;
	vv.vec[0][1] = 3;
	vv.vec[0][2] = 4;
	vv.ttransvec33();
	mat.tm();
	vec33 tvec3 = vv * mat;

	cout << vv.vec[0][0] << " ";
	cout << vv.vec[1][0] << " ";
	cout << vv.vec[2][0] << endl << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-4 4��� 1 4��ġ���� ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}" << endl 
		<< "���ϱ�" << endl << "{1,2,3,4}" << "<------���� ��ġ���� ���" << endl << "=" << endl;
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

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-3x3 ��İ� ����, ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl << "���ϱ�" << endl << "{1,2,3}" 
		<< endl << "{1,2,3}" << endl << "{1,2,3}" << endl << "=" << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mtp3.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl << "����" << endl
		<< "{1,2,3}" << endl << "{1,2,3}" << endl << "{1,2,3}" << endl << "=" << endl;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mtm3.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-4x4 ��İ� ����, ����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}" << endl << "���ϱ�" 
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
		 << "����" << endl << "{1,2,3,4}" << endl << "{1,2,3,4}" << endl <<
		"{1,2,3,4}" << endl << "{1,2,3,4}" << endl << "=" << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matm4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-33 ��� �����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1}" << endl << "{2,2,2}" << endl << "{3,3,3}" << endl << "���ϱ�" 
		 << endl << "3" << endl << "�������?" << endl;
	
	mat.cmtmat3(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mat.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-44 ��� �����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,1,1,1}" << endl << "{2,2,2,2}" << endl << "{3,3,3,3}" << endl << "{4,4,4,4}" 
		 << endl << endl << "���ϱ�" << endl << "4" << endl << "=" << endl;
	mat4.ctmt4(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << mat4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-33 ��� ���������-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{3,3,3}" << endl << "{6,6,6}" << endl 
		 << "{9,9,9}" << endl << "������" << endl << "3" << endl << "=" << endl;
	mat.cdvmat3(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mat.mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-44 ��� ���������-�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{2,2,2,2}" << endl << "{4,4,4,4}" << endl << "{6,6,6,6}" << endl 
		 << "{8,8,8,8}" << endl << endl << "������" << endl << "2" << endl << "=" << endl;
	mat4.ctds4(2);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << mat4.mat4[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-13���� �����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,2,3}" << endl << endl << "���ϱ�" << endl << "3" << endl << "=" << endl;
	v.vec[0][0] = 1; v.vec[0][1] = 2; v.vec[0][2] = 3;
	v.cmtvec3(3);

	cout << v.vec[0][0] << " ";
	cout << v.vec[0][1] << " ";
	cout << v.vec[0][2] << " ";
	cout << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-14���� �����-�ڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{1,2,3,4}" << endl << endl << "���ϱ�" << endl << "4" << endl << "=" << endl;
	v4.vec1[0][0] = 1; v4.vec1[0][1] = 2; v4.vec1[0][2] = 3; v4.vec1[0][3] = 4;
	v4.cmtvec4(4);

	cout << v4.vec1[0][0] << " ";
	cout << v4.vec1[0][1] << " ";
	cout << v4.vec1[0][2] << " ";
	cout << v4.vec1[0][3] << " ";
	cout << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-13���� ���������-�ڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{2,4,6}" << endl << endl << "������" << endl << "2" << endl << "=" << endl;
	v.vec[0][0] = 2; v.vec[0][1] = 4; v.vec[0][2] = 6;
	v.cdvvec3(2);

	cout << v.vec[0][0] << " ";
	cout << v.vec[0][1] << " ";
	cout << v.vec[0][2];
	cout << endl;

	cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡ�-14���� ���������-�ڡڡڡڡڡڡڡڡڡڡڡڡڡ� \n" << endl;
	cout << "{2,4,6,8}" << endl << endl << "������" << endl << "2" << endl << "=" << endl;
	v4.vec1[0][0] = 2; v4.vec1[0][1] = 4; v4.vec1[0][2] = 6; v4.vec1[0][3] = 8;
	v4.cdvvec4(2);

	cout << v4.vec1[0][0] << "  ";
	cout << v4.vec1[0][1] << "  ";
	cout << v4.vec1[0][2] << "  ";
	cout << v4.vec1[0][3] << "  ";
	cout << endl;
};