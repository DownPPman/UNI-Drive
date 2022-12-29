#pragma once

#include <GL/glew.h>
#include "Defines.h"

// simplifies the funktions that need to be caled when using the the vertex buffer


struct Vertex {
	float32 x;
	float32 y;
	float32 z; //remove later

};


struct VertexBuffer {

	//VertexBuffer constructor
	VertexBuffer(void* data, uint32 numVertecies) {
		//generates and binds an vao
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &bufferId);
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		glBufferData(GL_ARRAY_BUFFER, numVertecies * sizeof(Vertex), data, GL_STATIC_DRAW);//verwendungszweck + große + void zeiger zu daten + what to do with it
		glEnableVertexAttribArray(0);	//sagt mit welches attribut opengl ausführen soll
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(struct Vertex, x)); // anfangselement + elementen count + abstand zum nächsten Vertex(3*..)  +  ab wo componente beginnt)

		//unbinden des VAO
		glBindVertexArray(vao);

	}
	//VertexBuffer virtueller destructor to destruckt as a Derived Objekt
	virtual ~VertexBuffer() {
		glDeleteBuffers(1, &bufferId);
		

	}
	void bind() {
		glBindVertexArray(vao);
		/*
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		glEnableVertexAttribArray(0);	//sagt mit welches attribut opengl ausführen soll
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(struct Vertex, x)); // anfangselement + elementen count + abstand zum nächsten Vertex(3*..)  +  ab wo componente beginnt)
		
		this would be needet id we didnt use the vao
		*/

	}

	void unbind() {

		glBindVertexArray(0);


		/*
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		this would be needet id we didnt use the vao
			*/

	}


private:
	GLuint bufferId;
	GLuint vao; //vertexy array objekt


};

