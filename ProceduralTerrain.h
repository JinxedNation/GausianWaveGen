#pragma once

#include <cmath>

#include <vector>
#include <random>
#include <algorithm>
#include "TextureLoader.h"
#include "JPG_Loader.h"
#include "PNG_Loader.h"
#include "Terrain.h"
#include "BrushTerrain.h"
#include "AssetShader.h"

typedef struct
{
    float waterFlow;
    float sedimentRunOff;
}
LakeTypeData;


class ProceduralTerrain : public Terrain
{
    public:

        ProceduralTerrain();

            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        ProceduralTerrain(unsigned tempSize);
        

            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        ~ProceduralTerrain();



        void generateTexture();


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void setTerrainMaterial(const std::string& texturePath);//change with a std::shared ptr later


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void setTerrainShader(std::shared_ptr<TextureLoader> terrainShader);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void setSize(int tempWidth, int tempHeight);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void setTerrainWaterLevels(float tempLevels);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float getTerrainScaledLength() const;


            /********************************************************************************************************
             * @brief : getTerrainScaledHeight() const
             * @brief :
             *******************************************************************************************************/

        float getTerrainScaledHeight() const;


            /********************************************************************************************************
             * @brief : getTerrainScaledWidth() const
             * @brief :
             *******************************************************************************************************/

        float getTerrainScaledWidth() const;


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void getTerrainPoints();
        

            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        bool loadTerrainData(const char* readFileName, unsigned tempSize);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        bool createTerrain(const char* readFileName) override;


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void generateTerrain(int width, int height, float roughnes, int numOctaves, float persistence);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void simulateHeightmap(int xStart, int xEnd, int yStart, int yEnd, float tempRoughness);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void simulateErosion(std::vector<float>& m_MapWater, std::vector<float>& m_TerrainData);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void scaleTerrain(float scale_X, float scale_Y, float scale_Z);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void brushTerrain(int x_Coord, int y_Coord, float brushWeight, std::vector<float>& m_TerrainData);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void erodeMaterial(int x_Coord, int y_Coord, float amount, std::vector<float>& m_TerrainData, std::vector<float>& m_ErodedTerrain);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void erodeTerrain(int x_Coord, int y_Coord, float amount, std::vector<float>& m_TerrainData, std::vector<float>& m_ErodedTerrain);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void moveErodedMaterial(int x_Coord, int y_Coord, float total, std::vector<float>& m_TerrainData, std::vector<float>& m_ErodedTerrain);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void runErosion(std::vector<float>& m_MapWater, std::vector<float>& m_TerrainData, int numIterations, float errodedMaterialCap, float erosionRate, float depositSpeed);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void checkNextNode(int x_Coord, int y_Coord, void(*callback)(int, int));


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void dumpWater(int x_Coord, int y_Coord, float amount);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void evaporateWater(float evaporationSpeed);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void updateWaterLevel(float deltaT);
        
            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void updateCurrentWaterLevel(float waterChange);

            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void updateCurrentDebrisLevel(float debrisChange);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void updateSedimentLevel();


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateMinimum(const std::vector<float>& m_TerrainData) const;



            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateMaximum(const std::vector<float>& m_TerrainData) const;


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        LakeTypeData calculateFlowRate(int x_Start, int y_Start, int x_End, int y_End, const std::vector<float>& m_TerrainData, const std::vector<float>& m_MapWater, float flowRate);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateTerrainAngles(int x_Coord, int y_Coord);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateMovingMaterial(float slope, float water, float errodedMaterialCap);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateErosion(float tempSlope, float tempWater, float tempSediment);



            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateFolliage(float slope, float water, float errodedMaterialCap);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateWaterLevel(float waterLevel, float flowRate);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateErodedMaterial(float slope, float water, float amount);
        

            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateTerrainHeights(int x_Coord, int y_Coord) const;


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float calculateDropoff(int x_Coord, int y_Coord);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        float getDebrisLevel(float debrisLevel);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void resetTerrainNodes();


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void iterateDiamondSquare(int itrCounter, float m_TerrainRoughness);

        
            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void updateTerrain();


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void setErosionSpeed(float tempSpeed);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/



            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void setErosionValues(float tempRadius, float tempDepth, float tempCap);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void setWaterLevel(float tempWaterLevel);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void setViewMatrix(const glm::mat4& viewMat);


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void setProjMatrix(const glm::mat4& proj);
            
        
            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

        void draw();


            /********************************************************************************************************
             * @brief : getTerrainScaledLength() const
             * @brief :
             *******************************************************************************************************/

 

    private:
       
        glm::mat4 m_ViewMat;
        glm::mat4 m_ProjMat;

        std::vector<bool>  m_CheckedNode;
        std::vector<float> m_MapWater;
        std::vector<float> m_TerrainData;
        std::vector<float> m_ErodedTerrain;
        std::shared_ptr<TextureLoader> m_TerrainTexture; /// optimization std::shared_ptr<JPG_Loader> m_TerrainTexture;
        AssetShader* m_WorldShader;

        float m_ScaleHeight;
        float m_ScaleWidth;
        float m_ScaleLength;
        float m_Water;
        float m_Debris;
        float m_FlowRate;
        float m_MaxDebris;
        float m_MaxHeight;
        float m_DumpRate;
        float m_DistanceToPoint;
        float m_TerrainRoughness;

 
        float m_Radius;
        float m_Depth;
        int   m_TerrainHeight;

        int   m_BrushWeight;
        int   m_LakeSurface;
        int   m_LakeBed;
        int   m_LakeLeftSide;
        int   m_LakeRightSide;
        int   m_TerrainWidth;
        int   m_NumOctaves;
        float m_ErosionSpeed;
        int   m_TerrainPersistance;
        float m_WaterLevel;
        float m_DebrisLevel;
        float m_ErodedMaterialCap;
        float m_TerrainScale;
        static const int BRUSH_THICKNESS = 3.5;
        
        const float m_Rain        = 0.03f;
        const float m_Gravity     = 9.8f;
        const float m_Cohesion    = 0.1f;  
        const float m_TravelAngle = 25.0f;
        
        BrushTerrain m_Brush;
};