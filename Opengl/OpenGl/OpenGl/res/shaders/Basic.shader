#shader vertex
#version 330 
  
layout(location =0) in vec4 position; 
uniform vec2 xyData; // ���ڴ��� x �� y ����
out float zValue;
void main()  
{  
    float x =xyData.x;
    float y =xyData.y;
    float z = x + y;

    zValue = z;
    gl_Position = position;   
};

#shader fragment
#version 330  
in float zValue;
out vec4 color; 
void main()  
{  
    if (zValue < 300.0)
        color = vec4(1.0, 0.0, 0.0,1.0); // ��ɫ
    else if (zValue < 600.0)
        color = vec4(1.0, 0.0, 0.0,1.0); // ��ɫ
    else
        color = vec4(0.0, 1.0, 0.0,1.0); // ��ɫ 
};