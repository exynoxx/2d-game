#include <sGL.h>

char * shader::read_file (char *name){

	std::string line,text;
   	std::ifstream in(name);
   	while(std::getline(in, line))
   	{
       	text += line + "\n";
   	}
   	return (char * ) text.c_str();
}

void shader::create_shader_program (){

    /* --- VERTEX --- */
    char *vertex_string = read_file ("src/vertex.vs");
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_string, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
    }

    /* --- FRAGMENT --- */
    char *fragment_string = read_file ("src/fragment.fs");
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_string, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
    }

    /* --- LINK --- */
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void shader::use () {
	glUseProgram(shaderProgram);
}
