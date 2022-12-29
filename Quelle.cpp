
//#define _CRT_SECURE_NO_WARNINGS in properties
#include <stdio.h>
#include <iostream>
#define SDL_MAIN_HANDELT
#define GLEW_STATIC
#include <GL/glew.h>


#ifdef _WIN32
#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")
#else
#include <SDL2/SDL.h>
#endif
#include "Defines.h"
#include "vertex_buffer.h"
#include "Shader.h"





int main(int argc, char** argv)
{
	//Initialising of a new window & setting the Color sizes
	int DOUBLEBUFFER = 1; //1 = on 0 = of
	int SOUNDCHECK = 1; //1 = on 0 = of
	int SEASONS = 1; //1 = on 0 = of
	int DAY_NIGHT = 1; //1 = on 0 = of
	int EASYMODE = 1; //1 = on 0 = of

	


	SDL_Window* window;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); //buffersize per pixel
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, DOUBLEBUFFER);


	


	window = SDL_CreateWindow("Window 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 390, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);


	while (true) {
		SDL_GL_SwapWindow(window);

		GLenum err = glewInit();					//initialisieren der funktions zeiger !nach dem SDL_GLContext Setzen!
		if (err != GLEW_OK) {
			std::cout << "ein Fehler ist aufgetreten" << glewGetErrorString(err) << std::endl;
			std::cin.get();
			return -1;
		}
		std::cout << "openGL version:  " << glGetString(GL_VERSION) << std::endl;


		Vertex vertices[] = {				//array of vertices to send at Grafics Card
			Vertex{0.5f, -0.5f, 0.0f},
			Vertex{ -0.5f, -0.5f, 0.0f },
			Vertex{ 0.0f, 0.5f, 0.0f },
		};
		uint32 numVertices = 3;


		VertexBuffer vertexbuffer(vertices, numVertices);
		Shader shader("shaders/basic.frag", "shaders/basic.vert");
		shader.bind();
		



		bool close = false;
		while(!close){
			
			//code to clear the Buffer 
			glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			vertexbuffer.bind();
			glDrawArrays(GL_TRIANGLES, 0, numVertices);
			vertexbuffer.unbind();

			//warum drawt es immernoch??
			









			SDL_GL_SwapWindow(window);
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					close = true;
				}
			}
	
		}
	}


	return 0;

}


