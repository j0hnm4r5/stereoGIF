#pragma once

#include "ofMain.h"
#include "ofxAutostereogram.h"
#include "ofBall.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
	
		ofImage bgTile, depthMap, magicEye;
	
		ofBall** myBall;  
		int nBalls;
	
		ofFbo fbo;
	
		int i;
};
