#version 330 core


layout(location = 0) in vec3 posiotion;

void main()
{
	gl_position = vec4(position, 1.0f);
}
