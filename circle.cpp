#define PI 3.1415926535898 
GLint circle_points = 100;
int i;
float angle;
void circle(void){
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < circle_points; i++){
		angle = 2 * PI*i / circle_points;
		glVertex2f(cos(angle), sin(angle));
	}
	glEnd();
}