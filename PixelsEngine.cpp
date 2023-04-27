#include "PixelsEngine.h"
#include "PlayerCamera.h"   
#include "API_Factory.h"

PixelsEngine::PixelsEngine(unsigned windowWidth, unsigned windowHeight, const char* gameName) : m_PixelsWindow(new GameWindow(windowWidth, windowHeight, gameName)), m_PlayerCamera(nullptr), m_GraphicsAPI(nullptr), m_FactoryAPI(), m_WorldShader(nullptr), m_WorldEnvironment(new ProceduralTerrain(128)) {}


PixelsEngine::~PixelsEngine()
{

    shutdownPixelsEngine();
}


AssetShader* PixelsEngine::getWorldShader() const { return m_WorldShader; }






void PixelsEngine::loadPixelsEngine()
{
    loadGameWindow(m_WindowWidth, m_WindowHeight, m_ProjectTitle);
    loadGraphicsAPI();
    loadPlayerCamera(m_SpawnLocation);
    loadTerrainShader();
    loadWorldEnvironment();
   
    m_PixelsWindow->setPlayerInput(m_PlayerInput);
}


void PixelsEngine::runEngine()
{
    loadPixelsEngine();

    while (!glfwWindowShouldClose(m_PixelsWindow->getGameWindow()))
    {
        double deltaT            = m_PixelsWindow->getGameTimer();
        glm::vec3 cameraPosition = m_PlayerCamera->getPlayerPosition();
        m_PlayerInput->readInput(m_GLFWWindow, deltaT);
        renderWorld();
    }
}


void PixelsEngine::loadGameWindow(unsigned tempWindowWidth, unsigned tempWindowHeight, const char* tempGameName)
{
    m_ProjectTitle = tempGameName;
    m_WindowHeight = tempWindowHeight;
    m_WindowWidth  = tempWindowHeight;
    m_PixelsWindow->setGameWorld(m_WorldEnvironment);

    if (!m_PixelsWindow->ConfigureWindow(m_WindowWidth, m_WindowHeight, m_ProjectTitle))
    {
        return;
    }

    m_PixelsWindow->launchGame(this);
}



void PixelsEngine::loadPlayerCamera(glm::vec3& tempSpawnLocation)
{
    if (m_PlayerCamera)
    {
        delete m_PlayerCamera;
    }
    
    m_SpawnLocation = glm::vec3(0.0f, 0.0f, 2.0f);
    m_PlayerCamera  = new PlayerCamera(tempSpawnLocation);
    lastXCoord      = m_PixelsWindow->getGameWindowWidth() / 1.5;
    lastYCoord      = m_PixelsWindow->getGameWindowWidth() / 1.5;
    mouseMoved      = true;
}



void PixelsEngine::loadGraphicsAPI()
{
    m_GraphicsAPI = m_FactoryAPI.RunAPI("OPEN_GL");
    
    if (!m_GraphicsAPI)
    {
        return;
    }
    
    m_GraphicsAPI->runAPI();
    m_GraphicsAPI->setCameraView(1, 0.0, m_PixelsWindow->getGameWindowWidth(), m_PixelsWindow->getGameWindowHeight());
    m_GraphicsAPI->enableDepthTest();

    loadTerrainShader();
    m_WorldEnvironment->setTerrainShader(m_TexLoader);
}


void PixelsEngine::loadTerrainShader()
{
    if (!m_WorldShader)
    {
        m_WorldShader = new AssetShader("shaders/light_vs.shader", "shaders/light_fs.shader");
    }
    m_WorldEnvironment->setTerrainShader(m_TexLoader);
}



void PixelsEngine::loadWorldEnvironment()
{
    m_WorldEnvironment = new ProceduralTerrain(128);

    float terrainRoughness = 0.03;
    int numberOfOctaves = 12;
    float terrainPersist = 0.5;
    const int m_TerrainSize = 128;
    std::string textureEnvironment = "Earth.jpg";

    m_WorldEnvironment->generateTerrain(m_TerrainSize, m_TerrainSize, terrainRoughness, numberOfOctaves, terrainPersist);
    m_WorldEnvironment->scaleTerrain(0.8f, 0.3f, 1.5f);

    // Load texture
    m_TexLoader = std::make_shared<TextureLoader>(factory.generateTexture(textureEnvironment).release());

    // Set the terrain material and shader
    m_WorldEnvironment->setTerrainMaterial(textureEnvironment);
    m_WorldEnvironment->setTerrainShader(m_TexLoader);
    loadTerrainShader();
    m_PixelsWindow->setGameWorld(m_WorldEnvironment);

    
}



void PixelsEngine::renderWorld()
{
    setViewProjection();
    m_WorldEnvironment->draw();
    glfwSwapBuffers(m_GLFWWindow);
    glfwPollEvents();
}



void PixelsEngine::setViewProjection()
{
    m_View       = m_PlayerCamera->getViewMatrix();
    m_Projection = glm::perspective(glm::radians(45.0f), static_cast<float>(m_WindowWidth) / static_cast<float>(m_WindowHeight), 0.1f, 100.0f);

    m_PlayerCamera->setViewMatrix(m_View);
    m_PlayerCamera->setProjectionMatrix(m_Projection);
}



void PixelsEngine::shutdownPixelsEngine()
{
    delete m_PixelsWindow;
    m_PixelsWindow = nullptr;

    delete m_WorldShader;
    m_WorldShader = nullptr;
    
    delete m_PlayerCamera;
    m_PlayerCamera = nullptr;
    
    //delete m_GraphicsAPI;
    delete m_WorldEnvironment;
    m_WorldEnvironment = nullptr;

    m_GraphicsAPI = nullptr;
    glfwTerminate();
}





/****
* Notes : do this to optimize
* m_PlayerCamera = new PlayerCamera(tempSpawnLocation);
  with:
  m_PlayerCamera = std::make_unique<PlayerCamera>(tempSpawnLocation);
*/