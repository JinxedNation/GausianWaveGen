#pragma once


#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Testing texture class
#include "stb_image.h"
#include "Texture.h"

#include "Window.h"
#include "Shader.h"
#include "PlayerCamera.h"
#include "Terrain.h"
#include "Graphics_API.h"
// Math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Graphics
#include "Graphics_API.h"




namespace Lab {

	class LabEngine
	{

		public:
			Window* m_window;

			// camera object
			PlayerCamera* m_PlayerCam;
			float PreviousWidth;
			float PreviousHeight;
			bool firstMouse = true;

			// Objects
			Terrain *simpleTerrain;

			// graphics
			std::unique_ptr<Graphics_API> m_API;
		
			// deltaTime?
			float deltaTime = 0.0f;	// Time between current frame and last frame
			float lastFrame = 0.0f; // Time of last frame

			// TESTING VARIABLES/FEATURES
			bool canFly = false;

		// member functions

	

		// initialise all the objects we need for the game engine to work ( eg window object..)   (maybe this is called by the constructor?)
		void init();

		// running the engine, will be called from main entry point
		void run();

		// cleaning up everything once game loop ends
		void cleanUp();

		static LabEngine& getInstance();


		//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);


	private:

		// constructor
		LabEngine();
		// destructor
		~LabEngine();

		// deleting the copy + assignment
		LabEngine(const LabEngine&) = delete;
		LabEngine& operator=(const LabEngine&) = delete;

		// static instance of the engine
		static LabEngine* staticInstance;
	};
}
