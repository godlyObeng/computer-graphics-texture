#include <iostream>
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "loadimage.h"

#define WIDTH               600
#define HEIGHT              600

//global cube vertices
float r = 1.0f;
GLfloat vertices[8][3] = {
        {-r, r, r},
        {r, r, r},
        {-r, -r, r},
        {r, -r, r},

        {-r, r, -r},
        {r, r, -r},
        {-r, -r, -r},
        {r, -r, -r},
};

//global colours
GLfloat colours[6] = { 
	0.0f,
	1.0f / 6.0f,
	2 * (1.0f / 6.0f),
	3 * (1.0f / 6.0f),
	4 * (1.0f / 6.0f),
	5 * (1.0f / 6.0f)
};
void init();

void display(GLFWwindow* window);
void draw_cube_generic(GLfloat colour);
int main()
{
	//GLFW Initialisation
	if (!glfwInit()) {
		std::cout << "GLFW initialisation failed." << std::endl;
		return -1;
	}

	/*Creating the window*/
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GRA Assignment Texture", NULL, NULL);
	if (!window)
	{
		std::cout << "GLFW failed to create window." << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	init();

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {        std::cout << "GLEW initialisation failed: " << glewGetErrorString(err) << std::endl;
        return -1;    }

    GLuint tex = loadimage("Sprite_Dice.bmp");

    while (!glfwWindowShouldClose(window))
    {        glClear(GL_COLOR_BUFFER_BIT);

        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBindTexture(GL_TEXTURE_2D, tex);

		display(window);

        glDisable(GL_TEXTURE_2D);    }

    glfwTerminate();
    return 0;
}

void draw_cube_generic(GLfloat colour) {
	GLfloat r = 1.0f / 6.0f;
	glBegin(GL_TRIANGLES);
	//front
	glTexCoord2f(0.0f, 0.0f + colour); glVertex3fv(vertices[0]);
	glTexCoord2f(0.0f, r + colour); glVertex3fv(vertices[1]);
	glTexCoord2f(r, r + colour); glVertex3fv(vertices[3]);

	glTexCoord2f(0.0f, 0.0f + colour); glVertex3fv(vertices[0]);
	glTexCoord2f(r, r + colour); glVertex3fv(vertices[3]);
	glTexCoord2f(r, 0.0f + colour); glVertex3fv(vertices[2]);

	//back
	glTexCoord2f(6 * r, 0.0f + colour); glVertex3fv(vertices[4]);
	glTexCoord2f(5 * r, r + colour); glVertex3fv(vertices[7]);
	glTexCoord2f(6 * r, r + colour); glVertex3fv(vertices[5]);

	glTexCoord2f(6 * r, 0.0f + colour); glVertex3fv(vertices[4]);
	glTexCoord2f(5 * r, 0.0f + colour); glVertex3fv(vertices[6]);
	glTexCoord2f(5 * r, r + colour); glVertex3fv(vertices[7]);

	//right
	glTexCoord2f(2 * r, r + colour); glVertex3fv(vertices[1]);
	glTexCoord2f(3 * r, r + colour); glVertex3fv(vertices[5]);
	glTexCoord2f(3 * r, 0.0f + colour); glVertex3fv(vertices[7]);

	glTexCoord2f(2 * r, r + colour); glVertex3fv(vertices[1]);
	glTexCoord2f(3 * r, 0.0f + colour); glVertex3fv(vertices[7]);
	glTexCoord2f(2 * r, 0.0f + colour); glVertex3fv(vertices[3]);

	//left
	glTexCoord2f(4 * r, 0.0f + colour); glVertex3fv(vertices[0]);
	glTexCoord2f(3 * r, r + colour); glVertex3fv(vertices[6]);
	glTexCoord2f(4 * r, r + colour); glVertex3fv(vertices[4]);

	glTexCoord2f(4 * r, 0.0f + colour); glVertex3fv(vertices[0]);
	glTexCoord2f(3 * r, 0.0f + colour); glVertex3fv(vertices[2]);
	glTexCoord2f(3 * r, r + colour); glVertex3fv(vertices[6]);

	//top
	glTexCoord2f(2 * r, 0.0f + colour); glVertex3fv(vertices[0]);
	glTexCoord2f(r, r + colour); glVertex3fv(vertices[5]);
	glTexCoord2f(2 * r, r + colour); glVertex3fv(vertices[1]);

	glTexCoord2f(2 * r, 0.0f + colour); glVertex3fv(vertices[0]);
	glTexCoord2f(r, 0.0f + colour); glVertex3fv(vertices[4]);
	glTexCoord2f(r, r + colour); glVertex3fv(vertices[5]);

	//bottom
	glTexCoord2f(5 * r, 0.0f + colour); glVertex3fv(vertices[2]);
	glTexCoord2f(5 * r, r + colour); glVertex3fv(vertices[3]);
	glTexCoord2f(4 * r, r + colour); glVertex3fv(vertices[7]);

	glTexCoord2f(5 * r, 0.0f + colour); glVertex3fv(vertices[2]);
	glTexCoord2f(4 * r, r + colour); glVertex3fv(vertices[7]);
	glTexCoord2f(4 * r, 0.0f + colour); glVertex3fv(vertices[6]);



	glEnd();
}

/*Prints out the objects onto the display*/
void display(GLFWwindow* window) {

	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Rotates it diagonally for overall view
	glRotatef(0.05f, 7.5f, 7.5f, 1.0f);

	/*Draws the dice according to the second and repeats*/
	int time = glfwGetTime();
	draw_cube_generic(colours[time]);

	/*Resets the time back to zero which will draw the cyan dice and keeps the loop going infinitely*/
	if (glfwGetTime() > 6) {
		glfwSetTime(0);
	}
	/*Swap the windows*/
	glfwSwapBuffers(window);
	glfwPollEvents();
}

/*Initialises the functions*/
void init() {
	float bkg = 0.5f; //bkg color
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	/*Background colour*/
	glClearColor(bkg, bkg, bkg, bkg);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FLAT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.f * (GLfloat)WIDTH / 
		(GLfloat)HEIGHT, 5.f * (GLfloat)WIDTH / 
		(GLfloat)HEIGHT, -5.f, 5.f, -5.f, 5.f);

	/* Enable back-face culling */
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
}