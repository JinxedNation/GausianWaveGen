#pragma once
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include "ProceduralTerrain.h"


const float CameraYaw		  = -90.0f;
const float CameraPitch		  =   0.0f;
const float CameraSpeed		  =   3.0f;
const float CameraSensitivity =   0.2f;
const float CameraZoom	      =  45.0f;


enum MovementDirection
{
	LEFT,
	RIGHT,
	UP,
	BACK
};


class PlayerCamera
{
	public:
	

		PlayerCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = CameraYaw, float pitch = CameraPitch);

			/******************************************************************************************************************************************************************************
			 * @brief  : PlayerCamera()
			 * @brief  : 
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		PlayerCamera(float tempX, float tempY, float tempZ, float tempXUp, float tempYUp, float tempZUp, float tempYaw, float tempPitch);


			/******************************************************************************************************************************************************************************
			 * @brief  : getViewMatrix()
			 * @brief  : used to get the view matrix
			 * @return : glm::mat4
			 *****************************************************************************************************************************************************************************/

		glm::mat4 getViewMatrix();


			/******************************************************************************************************************************************************************************
			 * @brief  : getPlayerPosition()
			 * @brief  : used to get the position of the camera
			 * @return : m_Camera glm::vec3
			 *****************************************************************************************************************************************************************************/

		glm::vec3 getPlayerPosition() const;


			/******************************************************************************************************************************************************************************
			 * @brief  : getPlayerPosition()
			 * @brief  : used to get the position of the camera
			 * @return : m_Camera glm::vec3
			 *****************************************************************************************************************************************************************************/

		glm::vec3 getStartLocation(const Terrain& terrain) const;


			/*****************************************************************************************************************************************************************************
			 * @brief  : setViewMatrix()
			 * @brief  : used to set the camera view matrix
			 * 
			 * @param  : tempView - glm::mat4
			******************************************************************************************************************************************************************************/

		void setViewMatrix(glm::mat4 tempView);


			/*****************************************************************************************************************************************************************************
			 * @brief  : setProjectionMatrix()
			 * @brief  : used to set the camera projection matrix
			 * @param  : tempProjection - glm::mat4
			 * 
			 * @return : void
			******************************************************************************************************************************************************************************/

		void setProjectionMatrix(glm::mat4 tempProjection);


			/*****************************************************************************************************************************************************************************
			 * @brief  : readKeyboard()
			 * @brief  : used to read keyboard input from the user
			 * @return : void
			******************************************************************************************************************************************************************************/

		void readKeyboard(MovementDirection direction, float tempDeltaT);
	

			/******************************************************************************************************************************************************************************
			 * @brief  : readMouseMovement()
			 * @brief  : used to read mouse input from the user
			 * @param  : constrainPitch - bool 
			 * @param  : tempXOffSet	- float
			 * @param  : tempYOffSet	- float
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void readMouseMovement(float tempXOffSet, float tempYOffSet, GLboolean constrainPitch = true);
	

			/******************************************************************************************************************************************************************************
			 * @brief  : updateCameraValues()
			 * @brief  : used to update the camera values
			 * @param  : tempYOffset - float
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void readMouseScroll(float tempYOffSet);


			/******************************************************************************************************************************************************************************
			 * @brief  : updateCameraValues()
			 * @brief  : used to update the camera values
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void updateCameraValues();


			/******************************************************************************************************************************************************************************
			 * @brief  : movePlayerLeft()
			 * @brief  : enables the player the ability to move left
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void movePlayerLeft();


			/******************************************************************************************************************************************************************************
			 * @brief  : movePlayerRight()
			 * @brief  : enables the player the ability to move right
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void movePlayerRight();


			/******************************************************************************************************************************************************************************
			 * @brief  : movePlayerForward()
			 * @brief  : enables the player the ability to move foward
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void movePlayerForward();


			/******************************************************************************************************************************************************************************
			 * @brief  : movePlayerBack()
			 * @brief  : enables the player the ability to move backward 
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void movePlayerBack();



			/******************************************************************************************************************************************************************************
			 * @brief  : lookLeft()
			 * @brief  : enables the player the ability to look left
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void lookLeft();


			/******************************************************************************************************************************************************************************
			 * @brief  : updateCameraValues()
			 * @brief  : enables the player the ability to look right
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void lookRight();


			/******************************************************************************************************************************************************************************
			 * @brief  : lookUp()
			 * @brief  : enables the player the ability to look up
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void lookUp();


			/******************************************************************************************************************************************************************************
			 * @brief  : lookDown()
			 * @brief  : enables the player the ability to look down
			 * @return : void
			 ******************************************************************************************************************************************************************************/

		void lookDown();



	private:
		glm::vec3 start;
		ProceduralTerrain m_WorldTerrain;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjMatrix;
		glm::vec3 m_CameraPosition;   // direction
		glm::vec3 m_ForwardDir;       // front
		glm::vec3 m_UpDir;            // Up
		glm::vec3 m_LeftRight;       //  right horizontal
		glm::vec3 m_UpDown;			 //  WorldUp 
	
		float m_CameraPitch;		/// the cameras vertical angle
		float m_CameraYaw;			/// the cameras horizontal angle

		// camera options
		float m_Speed = 0.05f;
		float m_CameraZoom;

		float m_RotationSpeed;  ///mouse sensitivity
	

		glm::vec3 m_PointLight_Loc;
};