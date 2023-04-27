#include "GameWindow.h"


GameWindow::GameWindow(unsigned tempWidth, unsigned tempHeight, const char* tempTitle) : m_GameWindow(nullptr), m_PlayerCamera(nullptr), m_ManagePlayerInput(nullptr)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_ManagePlayerInput = new InputManager(m_GameWindow, m_PlayerCamera);


	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	m_GameWindow = glfwCreateWindow(tempWidth, tempHeight, tempTitle, nullptr, nullptr);

	if (!m_GameWindow)
	{
		glfwTerminate();

		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(m_GameWindow);
	glfwSwapInterval(1);
}


GameWindow::GameWindow(GLFWwindow* tempGameWindow) : m_GameWindow(tempGameWindow), m_PlayerCamera(new PlayerCamera()), m_ManagePlayerInput(nullptr)
{
	if (!m_GameWindow)
	{
		std::cerr << "Erorr GLFW was sent a null ptr " << std::endl;

		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(m_GameWindow);
	glfwSwapInterval(1);

	m_ManagePlayerInput = new InputManager(m_GameWindow, m_PlayerCamera);
}



GameWindow::~GameWindow()
{

}


unsigned GameWindow::getGameWindowWidth()   const { return m_WindowWidth;		}
unsigned GameWindow::getGameWindowHeight()  const { return m_WindowHeight;		}
const char*   GameWindow::getProjectTitle()	const { return m_ProjectTitle;		}
GLFWwindow*	  GameWindow::getGameWindow()   const { return m_GameWindow;		}
InputManager* GameWindow::getInputManager() const { return m_ManagePlayerInput; }






double GameWindow::getGameTimer() const
{
	static double previousTime = glfwGetTime();
	double currentTime		   = glfwGetTime();
	double deltaTime		   = currentTime - previousTime;
	previousTime			   = currentTime;

	return deltaTime;
}


void GameWindow::setGameWindowWidth(unsigned  tempWidth)   { m_WindowWidth  = tempWidth;  }
void GameWindow::setGameWindowHeight(unsigned  tempHeight) { m_WindowHeight = tempHeight; }


bool GameWindow::ConfigureWindow(unsigned tempWidth, unsigned tempHeight, const char* tempTitle)
{
	m_GameWindow = glfwCreateWindow(tempWidth, tempHeight, tempTitle, nullptr, nullptr);

	if (!m_GameWindow)
	{
		std::cerr << "Error can not make a GLFW game window " << std::endl;

		return false;
	}

	glfwMakeContextCurrent(m_GameWindow);
	glfwSwapInterval(1);

	return true;
}

void GameWindow::setGameWorld(ProceduralTerrain* tempWorld)
{
	m_WorldEnvironment = tempWorld;
}


void GameWindow::setPlayerInput(InputManager* tempInput)
{
	m_ManagePlayerInput = tempInput;
}


void GameWindow::setPixelsEngine(PixelsEngine* pixelsEngine)
{
	m_PixelsEngine = pixelsEngine;
}


void GameWindow::loadWorldEnvironment()
{
	
	// Configure the ProceduralTerrain object as needed
	int terrainSize = 128;
	float roughness = 0.03f;
	int numOctaves = 4;
	float persistence = 0.5f;

	m_WorldEnvironment->generateTerrain(terrainSize, terrainSize, roughness, numOctaves, persistence);
	m_WorldEnvironment->scaleTerrain(0.8, 0.3, 1.5);
	m_WorldEnvironment->setTerrainMaterial("Earth.jpg");
}




void GameWindow::launchGame(PixelsEngine* pixelsEngine)
{

	m_PixelsEngine = pixelsEngine;

	m_ManagePlayerInput->setupKeyboard();
	m_ManagePlayerInput->setupMouse();
	m_ManagePlayerInput->setupMouseWheel();


	double m_LastFrame;
	m_GameWindow = glfwCreateWindow(800, 600, "My Game", NULL, NULL);
	
	while(!glfwWindowShouldClose(m_GameWindow))
	{
		m_ManagePlayerInput->readInput(m_GameWindow, m_DeltaTime);
		m_PixelsEngine->renderWorld();
		m_DeltaTime = glfwGetTime() - m_LastFrame;
		m_LastFrame = glfwGetTime();
	}

	glfwTerminate();
	delete m_PlayerCamera;
}



void GameWindow::EndWindow()
{
	delete m_ManagePlayerInput;
	delete m_PlayerCamera;
	glfwDestroyWindow(m_GameWindow);
	glfwTerminate();
}