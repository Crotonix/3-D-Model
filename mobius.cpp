void mobius(void){
	for (double a = 0; a < 2 * PI; a += 0.2)
	{
		for (r = -1; r <= 1; r += 0.5)
		{
			glBegin(GL_LINE_STRIP);

			x = cos(a) *(2 + (r / 2 * cos(a / 2)));
			y = sin(a) *(2 + (r / 2 * cos(a / 2)));
			z = r / 2 * sin(a / 2);

			glVertex3f(x, y, z);


		}
		glEnd();
	}



	for (r = -1; r <= 1; r += 0.5)
	{

		for (double a = 0; a < 2 * PI; a += 0.2)
		{
			glBegin(GL_LINE_STRIP);

			x = cos(a) *(2 + (r / 2 * cos(a / 2)));
			y = sin(a) *(2 + (r / 2 * cos(a / 2)));
			z = r / 2 * sin(a / 2);

			glVertex3f(x, y, z);

		}
		glEnd();

	}


}