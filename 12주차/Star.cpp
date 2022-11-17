#include <chrono> 
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include "MusoenMath.h"

#pragma comment(lib, "OpenGL32")


using namespace std;
using namespace LJM;
chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;


GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
	vec3 pos;
	float r, g, b, a;
};


struct Transform
{
	mat3 translate;
	mat3 scale;
	mat3 rotation;
};




Vertex star[5];             // static mesh 
Vertex transformedStar[5];  //ȭ�鿡 �׸� ������ 
Vertex circle[360];             // static mesh  
Vertex transformedCircle[360];  // ȭ�鿡 �׷��� �� 


Transform transform;  //world ����� �� transform 


//<����>////////�������� ���°�//////////////////////////////////////////////////////////// 


float Xmu = 1.01f;
float Xm = 0.99f;
float X = 1.0f;
bool if_scale = false;


mat3 translate_m(
	1, 0, 0,
	0, 1, 0,
	0.001, 0, 1
);




mat3 rotation_m(
	cos(radians(1.0f)), -sin(radians(1.0f)), 0,
	sin(radians(1.0f)),  cos(radians(1.0f)), 0,
	0, 0, 1
);


mat3 scale_n(
	1.01, 0, 0,
	0, 1.01, 0,
	0, 0, 1.01
);


mat3 scale_m(
	0.99, 0, 0,
	0, 0.99, 0,
	0, 0, 0.99
);


////////////////////////////////////////////////////////////////////////////////////////// 


void Init();
void Update();
void Release();


static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


int main(void);




void Init()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);




	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSwapInterval(1);


	startRenderTimePoint = chrono::system_clock::now();




	//object������ 
	 /// Star(������) ���� 
	int i = 0;
	for (float theta = 0; theta < 360; theta += 72)
	{


		star[i].pos.vec[0][0] = -sin(radians(theta)) * 0.5f;      // x,y,z�� �� �� vec[0][0] vec[0][1] vec[0][2]�� �ٲ��ش�.
		star[i].pos.vec[0][1] = cos(radians(theta)) * 0.5f;
		star[i].pos.vec[0][2] = 1.0f;


		star[i].r = 0.3f;
		star[i].g = 0.0f;
		star[i].b = theta / 360.0f;
		star[i].a = 0.7f;




		transformedStar[i] = star[i];


		i++;
	}


	// �� ���� 
	for (int theta = 0; theta < 360; theta++)  
	{
		circle[theta].pos.vec[0][0] = sin(radians((float)theta)) * 0.5; //������ radians �Լ��� sin,cos�ȿ� �ִ´�
		circle[theta].pos.vec[0][1] = cos(radians((float)theta)) * 0.5; // x,y,z�� �� �� vec[0][0] vec[0][1] vec[0][2]�� �ٲ��ش�.
		circle[theta].pos.vec[0][2] = 1.0f;


		circle[theta].r = 0.3f;
		circle[theta].g = 0.0f;
		circle[theta].b = (float)theta / 360.0f;
		circle[theta].a = 0.7f;


		transformedCircle[theta] = circle[theta];
	}




	//Ʈ������ �ʱ�ȭ (�⺻�� ����) 
	transform.translate = mat3(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	);
	transform.rotation =mat3(
		cos(radians(0.0f)), sin(radians(0.0f)), 0,
		sin(radians(0.0f)),cos(radians(0.0f)), 0,
		0, 0, 1
	);
	transform.scale = mat3(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	);




}


void Release()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
void Update()
{
	while (!glfwWindowShouldClose(window))
	{
		//Update���� 
			//<����>////////////////////////////////////////////////////////////////////////////////// 


			//1. translate �� �����Ӵ� ���������� 0.001�� �������Ѽ� ��ü�� �̵��غ�����. 
			//2. Rotation �� �����Ӵ� 1���� �������Ѽ� ��ü�� ȸ�����Ѻ�����. 
			//3. Scale�� �ʴ� 0.01�� �ִ� 1.3����� �þ�ٰ� 0.7����� �پ�鵵�� ����ÿ� (�ݺ�) 
			//   (1.3�� �̻��� �Ǹ� �پ��� 0.7�� ���ϰ� �Ǹ� �ٽ� �þ�� ����ÿ�) 


		transform.translate = transform.translate * translate_m;


		transform.rotation = transform.rotation * rotation_m;




		if (if_scale == false)
		{
			transform.scale = transform.scale * scale_n;
			X = X * Xmu;
		}
		else if (if_scale == true)
		{
			transform.scale = transform.scale * scale_m;
			X = X * Xm;
		}


		if (X >= 1.3f)
		{
			if_scale = true;
		}
		else if (X <= 0.7f)
		{
			if_scale = false;
		}
		////////////////////////////////////////////////////////////////////////////////////////// 










		for (int i = 0; i < 360; i++)
		{
			transformedCircle[i].pos = circle[i].pos * transform.scale * transform.rotation * transform.translate;  
		}
		     // ����  circle.pos , translate, rotation scale ���δ� �� �ڵ��� ���� ������ �ٲ��־���.

		for (int i = 0; i < 5; i++)
		{
			transformedStar[i].pos = star[i].pos * transform.scale * transform.rotation * transform.translate;
		}






		//�� �ʱ�ȭ 
		glClearColor(.0f, 0.0f, 0.0f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);


		//���β� 
		glLineWidth(7.0f);
		//������ �׸��� 
		glBegin(GL_LINE_STRIP);


		int a = 0;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);   // x�� vec[0][0]���� y�� vec[0][1]�� �ٲ���
		glVertex3f(transformedStar[a].pos.vec[0][0], transformedStar[a].pos.vec[0][1], 0.0f);
		a = 3;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.vec[0][0], transformedStar[a].pos.vec[0][1], 0.0f);
		a = 1;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.vec[0][0], transformedStar[a].pos.vec[0][1], 0.0f);
		a = 4;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.vec[0][0], transformedStar[a].pos.vec[0][1], 0.0f);
		a = 2;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.vec[0][0], transformedStar[a].pos.vec[0][1], 0.0f);


		a = 0;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.vec[0][0], transformedStar[a].pos.vec[0][1], 0.0f);
		glEnd();


		//���׸��� 
		glBegin(GL_LINE_STRIP);
		for (int theta = 0; theta < 360; theta++)
		{
			glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
			glVertex3f(transformedCircle[theta].pos.vec[0][0], transformedCircle[theta].pos.vec[0][1], 0.0f);
		}
		glEnd();






		//ȭ�� ���� 
		glfwSwapBuffers(window);
		glfwPollEvents();


		//�����ð� ���� 
		renderDuration = chrono::system_clock::now() - startRenderTimePoint;
		startRenderTimePoint = chrono::system_clock::now();


		float fps = 1.0 / renderDuration.count();
		if (isFirstFrame == true)
		{
			isFirstFrame = false;
			continue;
		}
		if (renderDuration.count() < (1.0f / 60.0f))
			this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
		string fps_s = "FPS : " + to_string(fps);
		cout << fps_s << endl;


	}
}


static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


int main(void)
{
	Init();
	Update();
	Release();


	exit(EXIT_SUCCESS);
}