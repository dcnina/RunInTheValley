#version 330 core

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec3 fFragColor;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;
uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;
uniform sampler2D uTexture;

vec3 blinnPhong(){
	return uLightIntensity* (uKd * (dot(normalize(uLightDir_vs),vNormal_vs))+ uKs*(pow(dot((normalize(-vPosition_vs)+uLightDir_vs)/2,vNormal_vs),uShininess)));
}

void main()
{
	fFragColor = vec3(texture(uTexture,vTexCoords).xyz)*blinnPhong();
};
