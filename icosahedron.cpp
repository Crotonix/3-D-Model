#define X .525731112119133606 
#define Z .850650808352039932

static GLfloat vdata[12][3] = {
	{ -X, 0.0, Z }, { X, 0.0, Z }, { -X, 0.0, -Z }, { X, 0.0, -Z },
	{ 0.0, Z, X }, { 0.0, Z, -X }, { 0.0, -Z, X }, { 0.0, -Z, -X },
	{ Z, X, 0.0 }, { -Z, X, 0.0 }, { Z, -X, 0.0 }, { -Z, -X, 0.0 }
};
static GLuint tindices[20][3] = {
	{ 0, 4, 1 }, { 0, 9, 4 }, { 9, 5, 4 }, { 4, 5, 8 }, { 4, 8, 1 },
	{ 8, 10, 1 }, { 8, 3, 10 }, { 5, 3, 8 }, { 5, 2, 3 }, { 2, 7, 3 },
	{ 7, 10, 3 }, { 7, 6, 10 }, { 7, 11, 6 }, { 11, 0, 6 }, { 0, 1, 6 },
	{ 6, 1, 10 }, { 9, 0, 11 }, { 9, 11, 2 }, { 9, 2, 5 }, { 7, 2, 11 } };
int i,j;
GLfloat d1[3], d2[3], norm[3];

void normalize(float v[3]) {
	GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	if (d == 0.0) {
		printf("zero length vector");
		return;
	}
	v[0] /= d; v[1] /= d; v[2] /= d;
}

void normcrossprod(float v1[3], float v2[3], float out[3])
{
	GLint i, j;
	GLfloat length;

	out[0] = v1[1] * v2[2] - v1[2] * v2[1];
	out[1] = v1[2] * v2[0] - v1[0] * v2[2];
	out[2] = v1[0] * v2[1] - v1[1] * v2[0];
	normalize(out);
}

void drawtriangle(float *v1, float *v2, float *v3)
{
	glBegin(GL_TRIANGLES);
	glNormal3fv(v1); glVertex3fv(v1);
	glNormal3fv(v2); glVertex3fv(v2);
	glNormal3fv(v3); glVertex3fv(v3);
	glEnd();
}

void subdivide(float *v1, float *v2, float *v3)
{
	GLfloat v12[3], v23[3], v31[3];
	GLint i;

	for (i = 0; i < 3; i++) {
		v12[i] = v1[i] + v2[i];
		v23[i] = v2[i] + v3[i];
		v31[i] = v3[i] + v1[i];
	}
	normalize(v12);
	normalize(v23);
	normalize(v31);
	drawtriangle(v1, v12, v31);
	drawtriangle(v2, v23, v12);
	drawtriangle(v3, v31, v23);
	drawtriangle(v12, v23, v31);
}

void icosa(void){
	glBegin(GL_TRIANGLES);
	for (i = 0; i < 20; i++) {
		/* color information here */
		glVertex3fv(&vdata[tindices[i][0]][0]);
		glVertex3fv(&vdata[tindices[i][1]][0]);
		glVertex3fv(&vdata[tindices[i][2]][0]);
	}
	for (j = 0; j < 3; j++) {
		d1[j] = vdata[tindices[i][0]][j] - vdata[tindices[i][1]][j];
		d2[j] = vdata[tindices[i][1]][j] - vdata[tindices[i][2]][j];
	}
	normcrossprod(d1, d2, norm);
	glNormal3fv(norm);
	for (i = 0; i < 20; i++) {
		subdivide(&vdata[tindices[i][0]][0],
			&vdata[tindices[i][1]][0],
			&vdata[tindices[i][2]][0]);
	}
	glEnd();
}
