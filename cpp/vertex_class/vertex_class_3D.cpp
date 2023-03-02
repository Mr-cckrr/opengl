//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<iostream>
//
//#include<shader.h>
//
//#include<stb_image.h>
//
//#include<glm/glm/glm.hpp>
//#include<glm/glm/gtc/matrix_transform.hpp>
//#include<glm/glm/gtc/type_ptr.hpp>
//#include<camera.h>
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//bool firstMouse = true;
//float lastX = 800.0f/2.0f;
//float lastY = 600.0f / 2.0f;
//
//const unsigned int WIDTH = 1920;
//const unsigned int HEIGHT = 1080;
//
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//gl window setting:major page
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//gl window setting:minor page
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//
//
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "one", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	glEnable(GL_DEPTH_TEST);
//	Shader ourShader("glsl/vs_3D_one.txt", "glsl/fs_3D_one.txt");
//
//
//	float vertices[] = {
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//
//	glm::vec3 cubePositions[] = {
//	glm::vec3(0.0f,  0.0f,  0.0f),
//	glm::vec3(2.0f,  5.0f, -15.0f),
//	glm::vec3(-1.5f, -2.2f, -2.5f),
//	glm::vec3(-3.8f, -2.0f, -12.3f),
//	glm::vec3(2.4f, -0.4f, -3.5f),
//	glm::vec3(-1.7f,  3.0f, -7.5f),
//	glm::vec3(1.3f, -2.0f, -2.5f),
//	glm::vec3(1.5f,  2.0f, -2.5f),
//	glm::vec3(1.5f,  0.2f, -1.5f),
//	glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//
//	unsigned int VAO;
//	unsigned int VBO;
//
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	//glEnableVertexAttribArray(2);
//
//
//
//
//	unsigned int texture1, texture2;
//
//
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true);
//
//	unsigned char* data = stbi_load("wall.jpg", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//
//
//	data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//	//glUniform1i(glGetUniformLocation(ourShader.ID, "texturel"), 0);
//	ourShader.use();
//	ourShader.setInt("texture1", 0);
//	ourShader.setInt("texture2", 1);
//
//
//
//
//
//
//	while (!glfwWindowShouldClose(window))
//	{
//		float currentFrame = static_cast<float>(glfwGetTime());
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(window);
//		glClearColor(0.1f, 0.4f, 0.5f, 0.5f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		ourShader.use();
//
//
//		//glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
//		//vec = transform * vec;
//		//std::cout << vec.x << vec.y << vec.z << std::endl;
//
//
//
//
//
//
//		//float radius = 10.0f;
//		//float camX = static_cast<float>(sin(glfwGetTime()) * radius);
//		//float camZ = static_cast<float>(cos(glfwGetTime()) * radius);//spin
//
//		glm::mat4 projection = glm::mat4(1.0f);
//		projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//		ourShader.setMat4("projection", projection);
//
//
//		glm::mat4 view = glm::mat4(1.0f);
//		view = camera.GetViewMatrix();
//		ourShader.setMat4("view", view);
//
//
//
//		glBindVertexArray(VAO);
//		for (unsigned int i = 0; i < 10; i++)
//		{
//			glm::mat4 modl = glm::mat4(1.0f);
//			modl = glm::translate(modl, cubePositions[i]);
//			float angle = 20.0f * i;
//			modl = glm::rotate(modl, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//			ourShader.setMat4("modl", modl);
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//
//	return 0;
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//	/*float cameraSpeed = static_cast<float>(2.5f*deltaTime);*/
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.ProcessKeyboard(forward, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.ProcessKeyboard(backard, deltaTime);
//
//
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.ProcessKeyboard(left, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.ProcessKeyboard(right, deltaTime);
//
//	//cameraPos.y = 0.0f;//FPS camera
//	
//
//
//}
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
//{
//	float xpos = static_cast<float>(xposIn);
//	float ypos = static_cast<float>(yposIn);
//
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	float xoffset = xpos - lastX;
//	float yoffset = lastY - ypos;
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouseMovement(xoffset, yoffset);
//
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(static_cast<float>(yoffset));
//}