#version 330

// Input
in vec2 texcoord;

// Uniform properties
uniform sampler2D texture_1;
uniform sampler2D texture_2;
// TODO(student): Declare various other uniforms

// Output
layout(location = 0) out vec4 out_color;


void main()
{
    // TODO(student): Calculate the out_color using the texture2D() function.
   vec4 colour1 = texture2D(texture_1, texcoord);
   vec4 colour2 = texture2D(texture_2, texcoord);


   //out_color =colour1;
   out_color = mix(colour1, colour2, .5f);
   
	if (out_color.a < .5f)
	{
		discard;
	} 
}
