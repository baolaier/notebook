#shader vertex
#version 330 core
layout(location =0) in vec3 aPos;
out vec2 UV;
void main()
{
	UV = (aPos.xy+vec2(1.0,1.0))/2.0;
	gl_Position=vec4(aPos,1.0f);
}

#shader fragment
#version 330 core

in vec2 UV;
out vec4 color;

uniform sampler2D renderedTexture;
void main(){
    color = texture( renderedTexture, UV );

};