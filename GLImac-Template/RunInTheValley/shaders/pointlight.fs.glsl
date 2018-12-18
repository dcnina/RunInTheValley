#version 330 core

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec3 fFragColor;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;
uniform vec3 uLightPos_vs;
uniform vec3 uLightIntensity;
uniform sampler2D uTexture;

vec3 blinnPhong(){
	return (uLightIntensity / (distance(vPosition_vs,uLightPos_vs) * distance(vPosition_vs,uLightPos_vs)))* (uKd * (dot(normalize(uLightPos_vs - vPosition_vs),vNormal_vs))+ uKs*(pow(dot((normalize(-vPosition_vs)+normalize(uLightPos_vs - vPosition_vs))/2,vNormal_vs),uShininess)));
}

void main()
{
	fFragColor = vec3(texture(uTexture,vTexCoords).xyz)*blinnPhong();
};
