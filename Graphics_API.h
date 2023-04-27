#pragma once

#include <string>
#include <glad/glad.h>
#include <memory>

	/***************************************************************************************************************************************************************************************************************************************************************
	 * @class	: Graphics_API
	 * @breif	: A Graphics API class where the functions are mainly virtual and meant to be inherited by the child class.
	 * 
	 * 
	 * @version : 1.0
	 * @date    : April 2023
	 * @author  : William Halling
	 * @bug		:
	 *************************************************************************************************************************************************************************************************************************************************************************/

class Graphics_API
{
	public:

			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : runAPI()
			 * @breif : virtual as it will be over ridden in the child class 
			 ***************************************************************************************************************************************************************************************************************************************************************/

		virtual bool runAPI() = 0;


			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : clearBuffers()
			 * @breif : virtual as it will be over ridden in the child class 
			 ***************************************************************************************************************************************************************************************************************************************************************/

		virtual bool setGameWindow(void* windowManager) = 0;


			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : setCameraView()
			 * @breif : virtual as it will be over ridden in the child class 
			 ***************************************************************************************************************************************************************************************************************************************************************/

		virtual void setCameraView(int viewID, double tempXmin, double tempXMax, double tempYMin, double tempYMax, double tempNearZ, double tempFarZ) = 0;


			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : setCameraView()
			 * @breif : virtual as it will be over ridden in the child class 
			 ***************************************************************************************************************************************************************************************************************************************************************/

		virtual void setCameraView(int tempX, int tempY, int tempWidth, int tempHeight) = 0;


			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : renderTriangleStrip()
			 * @breif : virtual as it will be over ridden in the child class
			 ***************************************************************************************************************************************************************************************************************************************************************/

		virtual void enableDepthTest() = 0;


			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : bindVAO()
			 * @breif : virtual as it will be over ridden in the child class  
			 ***************************************************************************************************************************************************************************************************************************************************************/

		virtual void bindVAO(int tempVAO) = 0;
	

			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : unbindVAO()
			 * @breif : virtual as it will be over ridden in the child class  
			 ***************************************************************************************************************************************************************************************************************************************************************/

		virtual void unbindVAO() = 0;


			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : renderTriangleStrip()
			 * @breif : virtual as it will be over ridden in the child class
			 ***************************************************************************************************************************************************************************************************************************************************************/

		virtual void clearBuffers() = 0;


			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : renderTriangleStrip()
			 * @breif : virtual as it will be over ridden in the child class   
			 ***************************************************************************************************************************************************************************************************************************************************************/

			virtual bool drawTriangleStrip() = 0;


			/***************************************************************************************************************************************************************************************************************************************************************
			 * @brief : drawModel()
			 * @breif : virtual as it will be over ridden in the child class  
			 ***************************************************************************************************************************************************************************************************************************************************************/

		virtual bool drawModel() = 0;


};