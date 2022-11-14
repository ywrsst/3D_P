#pragma once
#include <iostream>
#include <cmath>
#include <stdio.h>


using namespace std;
namespace LJM {

	class mat3 {         // mat3 Ŭ���� ����
	public:

		float mat[3][3]  // 3x3 ��ı⺻��
		{
			{1,0,0},
			{0,1,0},
			{0,0,1}
		};
		float transmat[3][3]   // ��ġ�� �ٲ��� ���� transmat ����
		{
			{1,0,0},
			{0,1,0},
			{0,0,1}
		};

		float transmatt[3][3]  // ��ġ�� �ٲ��� ���� transmatt ����
		{
		    {1,0,0},
		    {0,1,0},
		    {0,0,1}
		};

		float mtt3[3][3] // 3x3 ��� ����
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

		mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i) //���� ���� ����
		{
			mat[0][0] = a; mat[0][1] = b; mat[0][2] = c; 
			mat[1][0] = d; mat[1][1] = e; mat[1][2] = f; 
			mat[2][0] = g; mat[2][1] = h; mat[2][2] = i; 
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

		void im() {    // ������� (identity matrix)  �ʱ�ȭ

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == j) {
						mat[i][j] = 1;
					}
					else {
						mat[i][j] = 0;
					}
				}
			}
		}

		void tm() {
			transmat[0][1] = mat[0][1];  //  ��ġ�� ���� �����̿��� transmat��  0 1 
			transmat[0][2] = mat[0][2];                                    // 0 2
			transmat[1][2] = mat[1][2];                                    // 1 2 �� �ִ´�.

			transmatt[1][0] = mat[1][0]; //  ��ġ�� ���� �����̿��� transmatt�� 1 0
			transmatt[2][0] = mat[2][0];                                   // 2 0
			transmatt[2][1] = mat[2][1];                                   // 2 1 �� �ִ´�.



			mat[0][1] = transmatt[1][0]; // transmat ������ transmatt ������ ����ִ� ���ڸ� �ݴ�� �־��ָ� ��ġ�� �ٲ��.
			mat[0][2] = transmatt[2][0];
			mat[1][2] = transmatt[2][1];

			mat[1][0] = transmat[0][1];
			mat[2][0] = transmat[0][2];
			mat[2][1] = transmat[1][2];

		}
		mat3 operator *(mat3 m)  // ������ �����ε�, ����   mat3 * mat3
		{ 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					mtt3[j][i] = 0;
					for (int k = 0; k < 3; k++) {
						mtt3[j][i] += mat[j][k] * m.mat[k][i];
					}
				}
			}

			return mat3
			(mtt3[0][0], mtt3[0][1], mtt3[0][2],
				mtt3[1][0], mtt3[1][1], mtt3[1][2],
				mtt3[2][0], mtt3[2][1], mtt3[2][2]);
		}


		mat3 operator +(mat3 m)  // ������ �����ε�, ����   mat3 + mat3
		{
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
				{
					mtt3[i][j] = mat[i][j] + m.mat[i][j];
				}
			}
			return mat3
			   (mtt3[0][0], mtt3[0][1], mtt3[0][2],
				mtt3[1][0], mtt3[1][1], mtt3[1][2],
				mtt3[2][0], mtt3[2][1], mtt3[2][2]);
		}


		mat3 operator -(mat3 m)  // ������ �����ε�, ����   mat3 - mat3
		{
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
				{
					mtt3[i][j] = mat[i][j] - m.mat[i][j];
				}
			}
			return mat3
			   (mtt3[0][0], mtt3[0][1], mtt3[0][2],
				mtt3[1][0], mtt3[1][1], mtt3[1][2],
				mtt3[2][0], mtt3[2][1], mtt3[2][2]);
		}
		void cmtmat3(int c)  // mat3 �����
		{
			mat[0][0] *= c; mat[0][1] *= c; mat[0][2] *= c;
			mat[1][0] *= c; mat[1][1] *= c; mat[1][2] *= c;
			mat[2][0] *= c; mat[2][1] *= c; mat[2][2] *= c;
		}

		void cdvmat3(int c)  // mat3 ���������
		{
			mat[0][0] /= c; mat[0][1] /= c; mat[0][2] /= c;
			mat[1][0] /= c; mat[1][1] /= c; mat[1][2] /= c;
			mat[2][0] /= c; mat[2][1] /= c; mat[2][2] /= c;
		}

	};

//----------------------------------------------------------------------------------------------------------------------- mat3

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

	vec3() {}

	vec3(float x, float y,float z) { // ��ǥ�� x,y�� ����
		vec[0][0] = x;
		vec[0][1] = y;
		vec[0][2] = z;
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

		for (int i = 0; i < 3; i++)
		{
			mt = mt + (vec[0][i] * m.mat[i][2]);
		}
		mtv[0][2] = mt;
		mt = 0;

		vec[0][0] = mtv[0][0];
		vec[0][1] = mtv[0][1];
		vec[0][2] = mtv[0][2];

		
		return vec3(vec[0][0], vec[0][1],vec [0][2]);   //��ü���� ��ȯ�Ѵ�
	}

	void cmtvec3(int c) // vec3 ��� ��
	{
		vec[0][0] *= c; vec[0][1] *= c;  vec[0][2] *= c;
	}

	void cdvvec3(int c) // vec3 ��� ������
	{
		vec[0][0] /= c; vec[0][1] /= c;  vec[0][2] /= c;
	}

	};

	
	class  vec33
	{
	public:

		float vec[3][1]   //  3 x 1 ������ �⺻�� 
		{
			 {0},
			 {0},
			 {1}
		};

		float mt = 0; // ������ ���� mt����
		float transvec[3][1]   //  ��ġ�� �ߴ� ���� ������ ����
		{
			{0},
			{0},
			{1}
		};

		float vec3[1][3]   //���Ͱ��� ������ ����
		{
			{0,0,1}
		};

		float vec31[1][3] // ���Ͱ��� ����� ���� ���� ������ ����
		{
		{0,0,1}
		};



		vec33(float x, float y, float z) //    x,y ��ǥ�� �޾ƿ´�.
		{
			vec3[0][0] = x;
			vec3[0][1] = y;
			vec3[0][2] = z;
		}

		void ttransvec33()   // ��ġ�� ���ٰ�
		{
			for (int i = 0; i < 3; i++)
			{
				vec[i][0] = vec[0][i];
			}
		}
		void idvec3()  // ���� ��� 
		{
			for (int i = 0; i < 3; i++)
			{
				vec3[0][i] = 1;
				vec[0][i] = 1;
			}
		}
		vec33 operator *(mat3 m) //  3x3��İ� 3x1���� ���� ������ �����ε�
		{
			transvec[0][0] = m.mat[0][0] * vec[0][0] + m.mat[0][1] * vec[1][0] + m.mat[0][2] * vec[2][0];
			transvec[1][0] = m.mat[1][0] * vec[0][0] + m.mat[1][1] * vec[1][0] + m.mat[1][2] * vec[2][0];
			transvec[2][0] = m.mat[2][0] * vec[0][0] + m.mat[2][0] * vec[1][0] + m.mat[2][2] * vec[2][0];


			vec[0][0] = transvec[0][0];
			vec[1][0] = transvec[1][0];
			vec[2][0] = transvec[2][0];


			return vec33(vec[0][0], vec[1][0], vec[2][0]);   //��ü���� ��ȯ�Ѵ�
		}
	};


	//---------------------------------------------------------------------------------------------------------------------vec3
	class matrix4
	{
	public:
		float mat4[4][4] // 4x4 ��� ����
		{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,0,1}
		};

		float transmat4[4][4] // ��ġ�� �ٲ��� ���� transmat4 ����
		{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,0,1}
		};

		float transmat44[4][4] // ��ġ�� �ٲ��� ���� transmat44 ����
		{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,0,1}
		};

		float mtt4[4][4] // 4x4 ��� ����
		{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,0,1}
		};
		float mt4 = 0; // ������ ���� mt4����
		float mtv4[4][1]; // ���Ұ��� ������ ����

		matrix4() {}

		matrix4(float x, float y, float z, float a) //  �̵� ��� ������ (x, y, z, a)
		{
			mat4[3][0] = x;
			mat4[3][1] = y;
			mat4[3][2] = z;
			mat4[3][3] = a;

		}

		matrix4(float s, float ss, float sss) // ũ�⺯ȯ��� ������(s, ss, sss)
		{
			mat4[0][0] = s;
			mat4[1][1] = ss;
			mat4[2][2] = sss;
		}
		matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i,
			float j, float k, float l, float m, float n, float o, float p) //���� ���� ����
		{
			mat4[0][0] = a; mat4[0][1] = b; mat4[0][2] = c; mat4[0][3] = d;
			mat4[1][0] = e; mat4[1][1] = f; mat4[1][2] = g; mat4[1][3] = h;
			mat4[2][0] = i; mat4[2][1] = j; mat4[2][2] = k; mat4[2][3] = l;
			mat4[3][0] = m; mat4[3][1] = n; mat4[3][2] = o; mat4[3][3] = p;
		}

		void im4() {    // ������� (identity matrix) �ʱ�ȭ

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (i == j) {
						mat4[i][j] = 1;
					}
					else {
						mat4[i][j] = 0;
					}
				}
			}
		}

		void tm4() {                // ��ġ��� (tm4 ����)
			transmat4[0][1] = mat4[0][1];
			transmat4[0][2] = mat4[0][2];
			transmat4[0][3] = mat4[0][3];
			transmat4[1][2] = mat4[1][2];
			transmat4[1][3] = mat4[1][3];
			transmat4[2][3] = mat4[2][3];

			transmat44[1][0] = mat4[1][0];
			transmat44[2][0] = mat4[2][0];
			transmat44[2][1] = mat4[2][1];
			transmat44[3][0] = mat4[3][0];
			transmat44[3][1] = mat4[3][1];
			transmat44[3][2] = mat4[3][2];

			mat4[0][1] = transmat44[1][0];
			mat4[0][2] = transmat44[2][0];
			mat4[0][3] = transmat44[3][0];
			mat4[1][2] = transmat44[2][1];
			mat4[1][3] = transmat44[3][1];
			mat4[2][3] = transmat44[3][2];

			mat4[1][0] = transmat4[0][1];
			mat4[2][0] = transmat4[0][2];
			mat4[2][1] = transmat4[1][2];
			mat4[3][0] = transmat4[0][3];
			mat4[3][1] = transmat4[1][3];
			mat4[3][2] = transmat4[2][3];
		}

		matrix4 operator *(matrix4 m)  // ������ �����ε�, ����   mat4 x mat4
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					mtt4[j][i] = 0;
					for (int k = 0; k < 4; k++) {
						mtt4[j][i] += mat4[j][k] * m.mat4[k][i];
					}
				}
			}
			return matrix4
			   (mtt4[0][0], mtt4[0][1], mtt4[0][2], mtt4[0][3],
				mtt4[1][0], mtt4[1][1], mtt4[1][2], mtt4[1][3],
				mtt4[2][0], mtt4[2][1], mtt4[2][2], mtt4[2][3],
				mtt4[3][0], mtt4[3][1], mtt4[3][2], mtt4[3][3]);
		}


		matrix4 operator +(matrix4 m)  //  ������ �����ε�, ����  mat4 + mat4
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++)
				{
					mtt4[j][i] = mat4[j][i] + m.mat4[j][i];
				}
			}
			return matrix4
			(mtt4[0][0], mtt4[0][1], mtt4[0][2], mtt4[0][3],
				mtt4[1][0], mtt4[1][1], mtt4[1][2], mtt4[1][3],
				mtt4[2][0], mtt4[2][1], mtt4[2][2], mtt4[2][3],
				mtt4[3][0], mtt4[3][1], mtt4[3][2], mtt4[3][3]);
		}


		matrix4 operator -(matrix4 m)  // ������ �����ε�, ����   mat4 - mat4
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++)
				{
					mtt4[j][i] = mat4[j][i] - m.mat4[j][i];
				}
			}
			return matrix4
			(mtt4[0][0], mtt4[0][1], mtt4[0][2], mtt4[0][3],
				mtt4[1][0], mtt4[1][1], mtt4[1][2], mtt4[1][3],
				mtt4[2][0], mtt4[2][1], mtt4[2][2], mtt4[2][3],
				mtt4[3][0], mtt4[3][1], mtt4[3][2], mtt4[3][3]);
		}

		void ctmt4(float c)              // mat4 ��� ��
		{
			mat4[0][0] *= c; mat4[0][1] *= c; mat4[0][2] *= c; mat4[0][3] *= c;
			mat4[1][0] *= c; mat4[1][1] *= c; mat4[1][2] *= c; mat4[1][3] *= c;
			mat4[2][0] *= c; mat4[2][1] *= c; mat4[2][2] *= c; mat4[2][3] *= c;
			mat4[3][0] *= c; mat4[3][1] *= c; mat4[3][2] *= c; mat4[3][3] *= c;
		}

		void ctds4(float c)            //  mat4 ��� ������
		{
			mat4[0][0] /= c; mat4[0][1] /= c; mat4[0][2] /= c; mat4[0][3] /= c;
			mat4[1][0] /= c; mat4[1][1] /= c; mat4[1][2] /= c; mat4[1][3] /= c;
			mat4[2][0] /= c; mat4[2][1] /= c; mat4[2][2] /= c; mat4[2][3] /= c;
			mat4[3][0] /= c; mat4[3][1] /= c; mat4[3][2] /= c; mat4[3][3] /= c;
		}
	};
	//------------------------------------------------------------------------------------------------------------------mat4

	class vec4 {     // vec4 Ŭ���� ����
	public:

		float vec1[1][4]   //  4 x 1 ������ �⺻�� 
		{
			{0,0,0,1}
		};
		float mt4 = 0; // ������ ���� mt4����
		float mtv4[4][1] // ��ġ�� ���� ������ ����
		{
			{0},
			{0},
			{0},
			{1}
		};
		float vecc[1][4]   // 44��İ� 14���� ���� ���� ������ ����
		{
			{0,0,0,1}
		};

		vec4(float x, float y, float z, float a) { // ��ǥ�� x,y,z�� ����
			vec1[0][0] = x;
			vec1[0][1] = y;
			vec1[0][2] = z;
			vec1[0][3] = a;
		}

		void transvec4()    //   vec4 ��ġ
		{
			for (int i = 0; i < 4; i++)
			{
				mtv4[i][0] = vec1[0][i];
			}
		}

		void iv4()        //    vec4 ���� ���
		{
			for (int i = 0; i < 4; i++)
			{
				vec1[0][i] = 1;
				mtv4[0][i] = 1;
			}
		}

		vec4 operator *(matrix4 m) //  ������ �����ε� ����
		{
			vecc[0][0] = m.mat4[0][0] * vec1[0][0] + m.mat4[1][0] * vec1[0][1] + m.mat4[2][0] * vec1[0][2] + m.mat4[3][0] * vec1[0][3];
			vecc[0][1] = m.mat4[0][1] * vec1[0][0] + m.mat4[1][1] * vec1[0][1] + m.mat4[2][1] * vec1[0][2] + m.mat4[3][1] * vec1[0][3];
			vecc[0][2] = m.mat4[0][2] * vec1[0][0] + m.mat4[1][2] * vec1[0][1] + m.mat4[2][2] * vec1[0][2] + m.mat4[3][2] * vec1[0][3];
			vecc[0][3] = m.mat4[0][3] * vec1[0][0] + m.mat4[1][3] * vec1[0][1] + m.mat4[2][3] * vec1[0][2] + m.mat4[3][3] * vec1[0][3];

			vec1[0][0] = vecc[0][0];
			vec1[0][1] = vecc[0][1];
			vec1[0][2] = vecc[0][2];
			vec1[0][3] = vecc[0][3];

			return vec4(vec1[0][0], vec1[0][1], vec1[0][2], vec1[0][3]);   //��ü���� ��ȯ�Ѵ�
		}
			/*for (int i = 0; i < 4; i++)
			{
				mt4 = mt4 + (vec[0][i]) * m.mat4[i][0];
			}
			mtv4[0][0] = mt4;
			mt4 = 0;

			for (int i = 0; i < 4; i++)
			{
				mt4 = mt4 + (vec[0][i] * m.mat4[i][1]);
			}
			mtv4[0][1] = mt4;
			mt4 = 0;

			for (int i = 0; i < 4; i++)
			{
				mt4 = mt4 + (vec[0][i] * m.mat4[i][2]);
			}
			mtv4[0][2] = mt4;
			mt4 = 0;
			for (int i = 0; i < 4; i++)
			{
				mt4 = mt4 + (vec[0][i] * m.mat4[i][3]);
			}
			mtv4[0][3] = mt4;
			mt4 = 0;

			vec[0][0] = mtv4[0][0];
			vec[0][1] = mtv4[0][1];
			vec[0][2] = mtv4[0][2];
			vec[0][3] = mtv4[0][3];*/

		void cmtvec4(int c) //  vec4 ��� ��
		{
			vec1[0][0] *= c; vec1[0][1] *= c;  vec1[0][2] *= c; vec1[0][3] *= c;
		}

		void cdvvec4(int c) // vec4 ��� ������
		{
			vec1[0][0] /= c; vec1[0][1] /= c;  vec1[0][2] /= c; vec1[0][3] /= c;
		}

	};
	//----------------------------------------------------------------------------------------------vec4

	class  vec44
	{
	public:

		float vec[1][4]   //  4 x 1 ������ �⺻�� 
		{
			 {0,0,0,1}
		};

		float vec41[4][1]   //  ��ġ�� �ߴ� ���� ������ ����
		{
			{0},
			{0},
			{0},
			{1}
		};

		float temvec[4][1]   //  4x4��İ� 4x1���͸� ���� ���� ������ ���� 
		{
			{0},
			{0},
			{0},
			{1}
		};
		float transvec41[4][1] // �� ���� �ӽ÷� ������ ����
		{
		{0},
		{0},
		{0},
		{1}
		};

		vec44(float x, float y, float z, float a) //    x,y,z ��ǥ�� �޾ƿ´�.
		{
			vec[0][0] = x;
			vec[0][1] = y;
			vec[0][2] = z;
			vec[0][3] = a;
		}

		void ttransvec44()   // ��ġ�� ���ٰ�
		{
			for (int i = 0; i < 4; i++)
			{
				vec41[i][0] = vec[0][i];
			}
		}
		vec44 operator *(matrix4 m) // 4x4��İ� 4x1���� ���� ������ �����ε�
		{
			transvec41[0][0] = m.mat4[0][0] * vec41[0][0] + m.mat4[0][1] * vec41[1][0] + m.mat4[0][2] * vec41[2][0] + m.mat4[0][3] * vec41[3][0];
			transvec41[1][0] = m.mat4[1][0] * vec41[0][0] + m.mat4[1][1] * vec41[1][0] + m.mat4[1][2] * vec41[2][0] + m.mat4[1][3] * vec41[3][0];
			transvec41[2][0] = m.mat4[2][0] * vec41[0][0] + m.mat4[2][1] * vec41[1][0] + m.mat4[2][2] * vec41[2][0] + m.mat4[2][3] * vec41[3][0];
			transvec41[3][0] = m.mat4[3][0] * vec41[0][0] + m.mat4[3][1] * vec41[1][0] + m.mat4[3][2] * vec41[2][0] + m.mat4[3][3] * vec41[3][0];

			vec41[0][0] = transvec41[0][0];
			vec41[1][0] = transvec41[1][0];
			vec41[2][0] = transvec41[2][0];
			vec41[3][0] = transvec41[3][0];

			return vec44(vec41[0][0], vec41[1][0], vec41[2][0], vec41[3][0]);   //��ü���� ��ȯ�Ѵ�
		}
	};
		//----------------------------------------------------------------------------------------------vec44
	};

