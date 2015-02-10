#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(5);


	i = 0;
	
	bgTile.loadImage("paper.jpg");
	bgTile.resize(128, 128);
	
//	depthMap.loadImage("shark.png");
//	depthMap.setImageType(OF_IMAGE_GRAYSCALE);
	
	gifLoader.load("kinect.gif");
	
	// allocate images
	depthMap.allocate(gifLoader.pages[0].getWidth(), gifLoader.pages[0].getHeight(), OF_IMAGE_GRAYSCALE);
	magicEye.allocate(depthMap.getWidth() + bgTile.getWidth(), depthMap.getHeight(), OF_IMAGE_COLOR);
	
	ofSetWindowShape(magicEye.width, magicEye.height + bgTile.getWidth());
	
	gifSaver.create("output.gif");


}

//--------------------------------------------------------------
void ofApp::update(){
	
	depthMap.setFromPixels(gifLoader.pages[i % 9]);
	depthMap.setImageType(OF_IMAGE_GRAYSCALE);
	
	i++;
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	float depthMultiplier = .2;
	ofxAutostereogram::makeAutostereogram(bgTile, depthMap, depthMultiplier, magicEye);

	magicEye.update();
	magicEye.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	if (i < 10) {
		ofImage img;
		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		gifSaver.append(img.getPixelsRef());
	}
	
	if (i == 10) {
		gifSaver.save();
		ofLog() << "SAVED";
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
