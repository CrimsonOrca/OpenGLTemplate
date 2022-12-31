#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class ObjectOutline
{
public:
	static void f1(); // call before render loop...

	static void f2(); // call before drawing objects we DO NOT want outlined; then, draw those not-outlined objects...

	static void f3(); // call before drawing object that are to be outlined; then, draw those objects as normal...

	static void f4(); // call before drawing scaled-up pure-color object...

	static void f5(); // call before exiting loop iteration; resets state...
};