#include "ofBall.h"

ofBall::ofBall(float _x, float _y, int _dim, int _r, int _g, int _b) {
	x = _x;
	y = _y;
	dim = _dim;
	r = _r;
	g = _g;
	b = _b;
	
	speedX = ofRandom(-50, 50);
	speedY = ofRandom(-50, 50);
	
}


void ofBall::update(){
	
	if (x < dim) {
			x = dim;
			speedX *= -1;
	} else if (x > ofGetWidth() - dim) {
			x = ofGetWidth() - dim;
			speedX *= -1;
	}
	
	
	if (y < dim) {
			y = dim;
			speedY *= -1;
	} else if (y > ofGetHeight() - dim) {
			y = ofGetHeight() - dim;
			speedY *= -1;
	} 
	
	x += speedX;
	y += speedY;
	
}


void ofBall::draw(){
	
	ofSetColor(r, g, b);
	ofCircle(x, y, dim);

}