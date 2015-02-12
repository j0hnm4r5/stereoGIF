#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(10);
	ofSetCircleResolution(100);
	
	bgTile.loadImage("soil.jpg");
	bgTile.resize(128, 128);
	
	// allocate images
	depthMap.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	fbo.begin();
		ofClear(255, 255, 255, 0);
	fbo.end();
	
	magicEye.allocate(depthMap.getWidth() + bgTile.getWidth(), depthMap.getHeight(), OF_IMAGE_COLOR);
	
	ofSetWindowShape(magicEye.width, magicEye.height + bgTile.getWidth());

	nBalls = 6;
	myBall = new ofBall*[nBalls];
		for (int i = 0; i < nBalls; i++){
			float x = ofRandom(0, ofGetWidth() - 100);
			float y = ofRandom(0, ofGetHeight());
			int dim = 250 - (50 + i * 25);
			int c = 100 + i * 31;

			myBall[i] = new ofBall(x, y, dim, c, c, c);

	}
	
	i = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < nBalls; i++) {
		myBall[i]->update();
	}
	
	fbo.begin();
	ofClear(0, 0, 0, 0);
	for (int i = 0; i < nBalls; i++) {
		myBall[i]->draw();
	}
	fbo.end();
	
	ofPixels pix;
	fbo.readToPixels(pix);
	depthMap.setFromPixels(pix);
	depthMap.setImageType(OF_IMAGE_GRAYSCALE);

	i++;
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	float depthMultiplier = .4;
	ofxAutostereogram::makeAutostereogram(bgTile, depthMap, depthMultiplier, magicEye);

	magicEye.update();
	magicEye.draw(0, 0, ofGetWidth(), ofGetHeight());
	

	if (i <= 10) {
		ofImage img;
		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		img.saveImage("output/output" + ofToString(i - 1) + ".png");

	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}
