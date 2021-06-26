#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "lp-common.h"
#include <cassert>

float* multiply(float* a, int row1, int col1, float* b, int row2, int col2)
{
	assert(col1 == row2);

	int size = row1 * col2;

	float* d = (float*) malloc(size * sizeof (float));

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			float sum = 0;
			for (int k = 0; k < col1; k++)
				sum = sum + a[i * col1 + k] * b[k * col2 + j];
			d[i * col2 + j] = sum;
		}
	}

	/*
	for (int i = 0; i < size; i++) {
		if (i % col2 == 0) {
			printf("\n");
		}
		printf("%.2f ", d[i]);
	}*/
	//printf("----------\n");

	return d;
}

int LP_helloTriangleLine ()  {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	static float vertices2[] = {
		 1.0f,  0.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
		 0.0f,  0.0f, 1.0f
	};


	static float vertices[] = {
	    -0.5f, -0.5f, 0.0f, 
	     0.5f, -0.5f, 0.0f, 
	     0.0f,  0.5f, 0.0f
	};  		



	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);


		//  ¿call to graphic card an buffer vertex object?
		static float rad = 0.0f;
		static float def = 0.0f;
		rad += 0.01f;
		def += (1.01f * sin(rad));
		// Z ?
		vertices2[0] = cos(rad);
		vertices2[1] = -sin(rad);
		vertices2[2] = 0;

		vertices2[3] = sin(rad);
		vertices2[4] = cos(rad);
		vertices2[5] = 0;

		vertices2[6] = 0;
		vertices2[7] = 0;
		vertices2[8] = 1;// sin(rad);
		

		// x ?
		/*
		vertices2[0] = 1;
		vertices2[1] = 0;
		vertices2[2] = 0;


		vertices2[3] = 0;
		vertices2[4] = cos(rad);
		vertices2[5] = -sin(rad);

		vertices2[6] = 0;
		vertices2[7] = sin(rad);
		vertices2[8] = cos(rad);
		*/

		float* n = multiply(vertices, 3, 3, vertices2, 3, 3);
		

		unsigned int VBO;

		unsigned int VertexArrayID;
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);

		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), n, GL_DYNAMIC_DRAW);


		glEnableVertexAttribArray(0);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);


		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_LINE_BIT, 0, 3);
		
		glDrawArrays(GL_POINTS, 0, 3);


		free(n);
		glDisableVertexAttribArray(0);


		// check and call events and swap the buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	return 0;
}
