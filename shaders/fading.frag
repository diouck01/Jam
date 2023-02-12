#version 120

uniform sampler2D texture;

void main()
{
    vec4 color = texture2D(texture, gl_TexCoord[0].xy);
    float subr = 0.01 * float(color.r > 0);
    float subg = 0.01 * float(color.g > 0);
    float subb = 0.01 * float(color.b > 0);
    float alpha = color.a * float(color.r > 0 || color.g > 0 || color.b > 0);
    gl_FragColor = vec4(color.r - subr, color.g - subg, color.b - subb, alpha);
}
