#define STB_IMAGE_IMPLEMENTATION
#include<stdio.h>
#include<stdlib.h>
#include<GLFW/glfw3.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stb/stb_image.h>

GLuint left = 0;
GLuint right = 0;
void key_callback();

int main(){
   if(!glfwInit()){
      //printf("Failed to initialize GLFW!\n");
      system("notify-send 'Failed to initialize GLFW'");
      return 1;
   }
   GLFWwindow* window = glfwCreateWindow(1054, 1057, "Title", NULL, NULL);
   if(window == NULL){
      //printf("Window creation failed!\n");
      system("notify-send 'Window creation failed!'");
      return 1;
   }
   glfwSetKeyCallback(window, key_callback);
   glfwMakeContextCurrent(window);
   glShadeModel(GL_SMOOTH);
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   glClearDepth(1.0f);
   glEnable(GL_TEXTURE_2D);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
   glMatrixMode(GL_PROJECTION);
   gluPerspective(45.0f, (float)1054/(float)1057, 0.1f, 100.0f);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   float translatetri = 0.0f;
   float translatequad = 0.0f;
   float rotationx = 0.0f;
   float rotationy = 0.0f;
   float ambientlight[] = {0.5f, 0.5f, 0.5f, 1.0f};
   float diffuselight[] = {1.0f, 1.0f, 1.0f, 1.0f};
   float lightposition[] = {1.0f, 0.0f, -1.0f, 1.0f};
   float currentframe = 0.0f;
   float lastframe = 0.0f;
   float deltatime = 0.0f;
   int texwidth, texheight, texnum;
   unsigned char* bytes = stbi_load("wood.jpg", &texwidth, &texheight, &texnum, 0);
   GLuint texture;
   glGenTextures(1, &texture);
   glBindTexture(GL_TEXTURE_2D, texture);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texwidth, texheight, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
   glLightfv(GL_LIGHT1, GL_AMBIENT, ambientlight);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuselight);
   glLightfv(GL_LIGHT1, GL_POSITION, lightposition);
   glEnable(GL_LIGHT1);
   glEnable(GL_LIGHTING);
   while(!glfwWindowShouldClose(window)){
      glfwPollEvents();
      glfwSwapBuffers(window);
      currentframe = glfwGetTime();
      deltatime = currentframe - lastframe;
      lastframe = currentframe;
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glTranslatef(translatetri, 0.0f, 0.0f);
      glTranslatef(0.0f, 0.0f, -5.0f);
      glRotatef(rotationx, 0.0f, 1.0f, 0.0f);
      glRotatef(rotationy, 1.0f, 0.0f, 0.0f);
      /*
      if(left == 1){
         translatetri += 1.0f * deltatime;
      }
      if(right == 1){
         translatetri += -1.0f * deltatime;
      }
      */
      glBegin(GL_QUADS);
         //glColor3f(1.0f, 0.0f, 0.0f);
	 glNormal3f(0.0f, 0.0f, 1.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
	 glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
         glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
	 //glColor3f(0.0f, 1.0f, 0.0f);
	 glNormal3f(1.0f, 0.0f, 0.0f);
	 glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
	 glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
	 glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
	 glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
	 //glColor3f(0.0f, 0.0f, 1.0f);
	 glNormal3f(0.0f, 0.0f, -1.0f);
	 glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	 glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);
	 glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
	 glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
	 //glColor3f(0.0f, 1.0f, 1.0f);
	 glNormal3f(-1.0f, 0.0f, 0.0f);
	 glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
	 glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
	 glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);
	 glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	 //glColor3f(1.0f, 1.0f, 1.0f);
	 glNormal3f(0.0f, -1.0f, 0.0f);
	 glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
	 glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	 glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
	 glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
	 glNormal3f(0.0f, 1.0f, 0.0f);
	 glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
	 glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);
	 glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
	 glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
      glEnd();
      rotationx +=  50.0f * deltatime;
      rotationy +=  12.5f * deltatime;
      if(rotationx > 360.0f){
         rotationx = rotationx - 360.0f;
      }
      if(rotationx < 0.0f){
         rotationx = 360.0f + rotationx;
      }
      if(rotationy > 360.0f){
         rotationy = rotationy - 360.0f;
      }
      if(rotationy < 0.0f){
         rotationy = 360.0f + rotationy;
      }
   }
   return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
   if(key == GLFW_KEY_A && action == GLFW_PRESS){
      left = 1;
   }else if(key == GLFW_KEY_A && action == GLFW_RELEASE){
      left = 0;
   }else if(key == GLFW_KEY_D && action == GLFW_PRESS){
      right = 1;
   }else if(key == GLFW_KEY_D && action == GLFW_RELEASE){
      right = 0;
   }
}
