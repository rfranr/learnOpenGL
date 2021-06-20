#ifndef __lp_common_h_
#define __lp_common_h_

/**
 * @brief      "However, the moment a user resizes the window the viewport should be adjusted as well. We can register a callback function on the window that gets called each time the window is resized. This resize callback function has the following prototype:"}
 *
 * @param      window  The window
 * @param[in]  width   The width
 * @param[in]  height  The height
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

/**
 * @brief      "GLFW's glfwGetKey function that takes the window as input together with a key. The function returns whether this key is currently being pressed."
 *
 * @param      window  The window
 */
void processInput(GLFWwindow *window);

#endif