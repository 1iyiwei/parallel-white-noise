R"(
#version 330
in vec2 ftexcoord;
layout(location = 0) out vec4 FragColor;
void main()
{
    FragColor.xy = ftexcoord.xy;
}
)"
