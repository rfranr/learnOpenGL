#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "lp-common.h"


int LP_createWindow ()  {
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


	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		
		// rendering ...
		
		// As you may recall from the OpenGL chapter, the glClearColor function is a state-setting function and glClear 
		// is a state-using function in that it uses the current state to retrieve the clearing color from.
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// check and call events and swap the buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}
