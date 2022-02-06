#include "ofApp.h"
#include <stdio.h>

int width = 1024;
int height = 768;

Splash::Splash() {

}


Splash::Splash(float x_pos, ofColor drop_color) {
	x = x_pos;
	x1 = 0;
	x2 = x_pos;
	y1 = height;
	y2 = height;
	radius = ofRandom(0.5, 3);
	speed = ofRandom(3, 5);
	color = drop_color;

};

void Splash::draw() {
	ofSetColor(color);
	ofDrawCircle(x, y1, radius);
	ofDrawCircle(x2, y1, radius);
};

void Splash::splash() {
	y1 = height-x1 ;//- 1 * pow(splash_x, 2) + height ;
	y2 = height-x1;
	x1 += speed;
	x2 = x2 - speed;
	x = x + speed;
	if (y1 <= height-10) {
		
		y1= 0;
		
	};

};

Drop::Drop() {
	x = ofRandom(width);
	y = ofRandom(-200, -500);
	z = ofRandom(1, 5);
	speed = ofRandom(4, 10) * z;
	length = ofRandom(2, 10) * z;
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	
};

void Drop::fall() {
	y = y + speed;


	if (y >= height) {
		if (z >= 4) {
			collision = Splash(x, color);
			
		}
		x = ofRandom(width);
		y = ofRandom(-200, -500);
		z = ofRandom(1, 5);
		speed = ofRandom(4, 10) * z;
		length = ofRandom(2,10) * z;

	}

};

void Drop::draw() {
	ofSetColor(color);
	ofDrawLine(x, y, x, y + length);
};

//--------------------------------------------------------------
void ofApp::setup(){

	

	for (int i = 0; i < n_drops; i++) {

		drops[i] = Drop();
	}


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawCurve((float)10.0, (float) 5.0, (float)20.0, (float)5.0, (float)15.0, (float) 3.0,(float)1.0,(float)2.0);

	for (int i = 0; i < n_drops; i++) {

		drops[i].fall();
		drops[i].draw();
		if (drops[i].collision.y1 >0) {
			drops[i].collision.splash();
			drops[i].collision.draw();
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
