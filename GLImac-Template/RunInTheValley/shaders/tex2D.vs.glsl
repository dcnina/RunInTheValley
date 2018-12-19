#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexTexture;

out vec2 vFragTexture;
out vec2 vPosition;

uniform mat3 uModelMatrix;


void main() {
	vFragTexture = aVertexTexture;
	vPosition = aVertexPosition;

	vec3 aVertexTransformed = uModelMatrix*vec3(aVertexPosition, 1);
	
	gl_Position = vec4(aVertexTransformed.xy, 0, 1);
}