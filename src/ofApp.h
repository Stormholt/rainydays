#pragma once

#include "ofMain.h"

class Splash {
public:
	float x;
	float x1;
	float x2;
	float y1;
	float y2;
	float speed;
	float radius;
	ofColor color;

	Splash();
	Splash(float x_pos, ofColor drop_color);
	void splash();
	void draw();
};

class Drop {
public:
	float x;
	float y;
	float z;
	float speed;
	float length;
	float thickness;
	Splash collision;
	ofColor color;
	Drop();
	void fall();
	void draw();

};



class ofApp : public ofBaseApp{
	static const int n_drops = 500;
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		Drop drops[n_drops];
		
};




