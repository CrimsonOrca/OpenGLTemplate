#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class DepthBufferManager {
	public:
		static void EnableTesting(bool status) {
			if (status)
				glEnable(GL_DEPTH_TEST);
			else
				glDisable(GL_DEPTH_TEST);
		}
};

struct StencilBufferValue
{
	static const int ZERO;
	static const int ONE;
};

struct StencilBufferTestCondition
{
	static const int NOT_EQUAL;
	static const int EQUAL;
};

struct StencilBufferTestResult
{
	static const int PASS;
};

const int StencilBufferValue::ZERO              { 0x00 }; // 0
const int StencilBufferValue::ONE               { 0xFF }; // 255
const int StencilBufferTestCondition::NOT_EQUAL { GL_NOTEQUAL };
const int StencilBufferTestCondition::EQUAL     { GL_EQUAL };
const int StencilBufferTestResult::PASS         { GL_ALWAYS };

class StencilBufferManager 
{
	public:

		static void EnableTesting(bool status)
		{
			if (status)
				glEnable(GL_STENCIL_TEST);
			else
				glDisable(GL_STENCIL_TEST);
		}

		static void SetValue(int value)
		{
			glStencilMask(value);
		}

		static void ConfigureTest(int condition, int referance = 1, int mask = StencilBufferValue::ONE)
		{
			glStencilFunc(condition, referance, mask);
		}

		static void ConfigureGlobalState()
		{
			DepthBufferManager::EnableTesting(true);
			StencilBufferManager::EnableTesting(true);
			StencilBufferManager::ConfigureTest(StencilBufferTestCondition::EQUAL);
			glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		}
};