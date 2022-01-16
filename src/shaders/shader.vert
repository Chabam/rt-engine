#version 400

in vec3 inPos;   // the position variable has attribute position 0
in vec3 inColor; // the color variable has attribute position 1

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 outColor;

void main()
{
    gl_Position = model * view * projection * vec4(inPos, 1.0);
    outColor = inColor; // set ourColor to the input color we got from the vertex data
}