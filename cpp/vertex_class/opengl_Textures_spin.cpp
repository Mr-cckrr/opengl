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
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
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
//	GLFWwindow* window = glfwCreateWindow(800, 600, "one", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	Shader ourShader("glsl/vs01.txt", "glsl/fs01.txt");
//
//	float vertices[] = {
//		 0.5f, 0.5f,0.0f,  1.0f,1.0f,
//		 0.5f,-0.5f,0.0f,  1.0f,0.0f,
//		-0.5f,-0.5f,0.0f,  0.0f,0.0f,
//		-0.5f, 0.5f,0.0f,  0.0f,1.0f
//	};
//
//	unsigned int indices[] = {
//		0,1,3,
//		1,2,3
//	};
//
//
//
//	unsigned int VAO;
//	unsigned int VBO;
//	unsigned int EBO;
//
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//		glClearColor(0.1f, 0.4f, 0.5f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//
//
//
//		//glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
//		//vec = transform * vec;
//		//std::cout << vec.x << vec.y << vec.z << std::endl;
//
//
//
//
//		glm::mat4 transform = glm::mat4(1.0f);//shift+alt+; 匹配多个相同字符
//		transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
//		transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, -1.0f));
//
//
//		ourShader.use();
//		unsigned int transformformLoc = glGetUniformLocation(ourShader.ID, "transform");
//		glUniformMatrix4fv(transformformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//
//
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
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
//}