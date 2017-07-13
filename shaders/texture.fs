#version 330 core
out vec4 FragColor;

in vec3 outColor;
in vec2 outTexCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, outTexCoord) * vec4(outColor, 1.0);
}
