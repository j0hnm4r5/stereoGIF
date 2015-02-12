#pragma once

#include "ofMain.h"

class ofBall {

	public:

		void update();
		void draw();
	
		ofBall(float x, float y, int dim, int r, int g, int b);

		// variables
		float x;
		float y;
		float speedY;
		float speedX;
		int dim;
		int r;
		int g;
		int b;

	

	private:

};