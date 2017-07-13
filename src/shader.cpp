#include <shader.h>

unsigned int shaderID_textue;
unsigned int shaderID_color;

char *read_file (char *name){
    FILE *f = fopen(name, "rb");
    fseek(f, 0, SEEK_END);
    int fsize = ftell(f);
    rewind(f);//fseek(f, 0, SEEK_SET);
    char *string = new char[fsize + 1];
    fread(string, fsize, 1, f);
    fclose(f);
    string[fsize] = 0;

    return string;
}

unsigned int create_shader_program (char *vs, char *fs){

    /* --- VERTEX --- */
    char *vertex_string = read_file (vs);
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_string, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << std::endl;
    }

    /* --- FRAGMENT --- */
    char *fragment_string = read_file (fs);
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_string, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED" << std::endl;

    }

    /* --- LINK --- */
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED" << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    delete(vertex_string);
    delete(fragment_string);

    return shaderProgram;
}

unsigned int get_shaderID_textue () {
    return shaderID_textue;
}

unsigned int get_shaderID_color () {
    return shaderID_color;
}

void set_shaderID_textue (unsigned int id) {
    shaderID_textue = id;
}

void set_shaderID_color (unsigned int id) {
    shaderID_color = id;
}
