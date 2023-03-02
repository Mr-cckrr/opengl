//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//const char* vertexShaderSource =
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColor;\n"
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos, 1.0);\n"
//"	ourColor=aColor;"
//"}\0";
//
//const char* fragmentShaderSource = 
//"#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 ourColor; \n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(ourColor,1.0f);\n"
//"}\n\0";
//
//
//
//
//int main() 
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);//gl window setting:major page
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);//gl window setting:minor page
//	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_COMPAT_PROFILE);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
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
//
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	glViewport(0, 0, 800, 600);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	unsigned int shaderPergram;
//	shaderPergram = glCreateProgram();
//	float vertices[] = {
//		 0.5f,-0.5f,0.0f, 1.0f,0.0f,0.0f,
//		-0.5f,-0.5f,0.0f, 0.0f,1.0f,0.0f,
//		 0.0f, 0.5f,0.0f, 0.0f,0.0f,1.0f
//	};
//
//
//	//unsigned int indices[] = {
//	//	0,1,2
//	//};
//
//
//	unsigned int VAO;
//	//unsigned int EBO;
//	unsigned int VBO;
//
//	
//	glGenVertexArrays(1, &VAO);
//	//glGenBuffers(1, &EBO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),(void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);
//	
//	
//	//glBindVertexArray(0);
//	glUseProgram(shaderPergram);
//
//	
//	
//
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX\n" << infoLog << std::endl;
//	}
//
//
//
//	glAttachShader(shaderPergram, vertexShader);
//	glAttachShader(shaderPergram, fragmentShader);
//	glLinkProgram(shaderPergram);
//
//	glGetProgramiv(shaderPergram, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderPergram, 512, NULL, infoLog);
//		std::cout << "ERORR::Program";
//	}
//
//
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//		glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		//float timeValue = glfwGetTime();
//		//float grennValue = sin(timeValue);
//		//int vertexColorLocation = glGetUniformLocation(shaderPergram, "ourColor");
//		//glUniform4f(vertexColorLocation,0.0f,grennValue,0.0f,1.0f);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		/*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);*/
//
//
//		glfwSwapBuffers(window);
//		glfwPollEvents(); 
//
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	//glDeleteBuffers(1, &EBO);
//	glDeleteProgram(shaderPergram);
//
//
//	glfwTerminate();
//	
//
//
//
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
//	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}