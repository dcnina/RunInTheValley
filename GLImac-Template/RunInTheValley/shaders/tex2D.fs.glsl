#version 330 core

in vec2 vFragTexture;

out vec3 fFragTexture;

uniform sampler2D uTexture;

void main() {

	//fFragTexture = vec3(1.f, 0.f, 0.f);
	fFragTexture = texture(uTexture, vFragTexture).xyz;
};