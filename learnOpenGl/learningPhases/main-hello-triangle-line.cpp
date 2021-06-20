#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "lp-common.h"

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

	static float vertices[] = {
	    -0.5f, -0.5f, 0.0f, 
	     0.5f, -0.5f, 0.0f, 
	     0.0f,  0.5f, 0.0f
	};  		

	//  ¿call to graphic card an buffer vertex object?
	unsigned int VBO;
	
	unsigned int VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);  

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		glEnableVertexAttribArray(0);  

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		glDrawArrays(GL_LINE_LOOP, 0, 3);

		glDisableVertexAttribArray(0);

		// check and call events and swap the buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}
