#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <functional>
#include <iostream>
#include <string>

#include "Terrain.h"
#include "stb_image.h"
#include "GameWindow.h"
#include "AssetShader.h"
#include "API_Factory.h"
#include "Graphics_API.h"
#include "PlayerCamera.h"
#include "InputManager.h"
#include "ProceduralTerrain.h"
#include "TextureLoader_Factory.h"


class PixelsEngine
{
public:

    PixelsEngine(unsigned windowWidth, unsigned windowHeight, const char* gameName);
    ~PixelsEngine();
    
    void setViewProjection();
    AssetShader* getWorldShader() const;


    void runEngine();

    void renderWorld();

    void shutdownPixelsEngine();
   


private:

    void loadPixelsEngine();
    void loadGameWindow(unsigned tempWindowWidth, unsigned tempWindowHeight, const char* tempGameName);
    void loadPlayerCamera(glm::vec3& tempSpawnLocation);
    void loadGraphicsAPI();
    void loadTerrainShader();
    void loadWorldEnvironment();


    std::string m_TerrainMat;
    PlayerCamera*       m_PlayerCamera;
    ProceduralTerrain*  m_WorldEnvironment;
    API_Factory         m_FactoryAPI;
    JPG_Loader m_TextureLoad;
    GLFWwindow*   m_GLFWWindow;
    GameWindow*   m_PixelsWindow;
    AssetShader*  m_WorldShader;
    InputManager* m_PlayerInput;
    TextureLoader_Factory factory;
   
    std::shared_ptr<TextureLoader> m_TexLoader;
    float lastXCoord;
    float lastYCoord;
    bool  mouseMoved;

    unsigned m_WindowWidth;
    unsigned m_WindowHeight;
    const char*        m_ProjectTitle;
    glm::vec3          m_SpawnLocation;



    glm::mat4 m_Projection;
    glm::mat4 m_View;
    std::unique_ptr<ProceduralTerrain>* m_WorldTerrain;
    std::unique_ptr<Graphics_API> m_GraphicsAPI;
};
/***
* future work
/// .getGameTitle
/// .getWindowHeight
/// .getWindowWidth - 
**/