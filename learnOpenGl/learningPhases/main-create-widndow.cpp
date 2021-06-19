#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/**
 * @brief      "However, the moment a user resizes the window the viewport should be adjusted as well. We can register a callback function on the window that gets called each time the window is resized. This resize callback function has the following prototype:"}
 *
 * @param      window  The window
 * @param[in]  width   The width
 * @param[in]  height  The height
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

/**
 * @brief      "GLFW's glfwGetKey function that takes the window as input together with a key. The function returns whether this key is currently being pressed."
 *
 * @param      window  The window
 */
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

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
