//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//
//
//static unsigned int CompileShader(unsigned int type,const std::string& source )
//{
//	unsigned int id = glCreateShader(type);
//
//	const char* src = source.c_str();
//
//	glShaderSource(id, 1, &src, nullptr);
//	glCompileShader(id);
//
//	int result;
//	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
//	if (!result == GL_FALSE)
//	{
//		int length;
//		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
//		char* massage = (char*)alloca(length *sizeof(char));
//		glGetShaderInfoLog(id, length, &length, massage);
//		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")<<std::endl;
//		std::cout << massage << std::endl;
//		glDeleteShader(id);
//		return 0;
//	}
//	return id;
//}
//
//
//static unsigned int CreateShaer(const std::string& vertexShader, const std::string& fragementShader)
//{
//	unsigned int program = glCreateProgram();
//	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
//	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragementShader);
//
//	glAttachShader(program, vs);
//	glAttachShader(program, fs);
//	glLinkProgram(program);
//	glValidateProgram(program);
//
//	glDeleteShader(vs);
//	glDeleteShader(fs);
//
//
//	return program;
//}
//
//int main(void)
//{
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    glewInit();
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    if (glewInit() != GLEW_OK)
//        std::cout << "Error" << std::endl;
//
//    float positions[6] = {
//		-0.5f,-0.5f,
//		 0.0f, 0.5f,
//		 0.5f,-0.5f,
//	};
//
//    unsigned int buffer;
//	glGenBuffers(1, &buffer);
//	glBindBuffer(GL_ARRAY_BUFFER, buffer);
//	glBufferData(GL_ARRAY_BUFFER,6*sizeof(float),positions,GL_STATIC_DRAW);//绑定数组
//
//    glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);
//
//
//	std::string vertexShader =
//		R"glsl(#version 330 core \n"
//		"\n"
//		"layout(location = 0) in vec4 position;\n"
//		"\n"
//		"viod main()\n"
//		"{\n"
//		"	gl_Position  = position;\n"
//		"}\n)glsl";
//
//	std::string fragmentShader =
//		R"glsl(#version 330 core\n"
//		"\n"
//		"layout(location = 0) out vec4 color\n"
//		"void main()\n"
//		"{\n"
//		"   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
//		"}\n)glsl";
//
//	unsigned int shader = CreateShaer(vertexShader,fragmentShader);
//	glUseProgram(shader);
//
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//		glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
//
//
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}