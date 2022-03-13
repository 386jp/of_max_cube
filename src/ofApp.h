#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxAssimpModelLoader.h"

#define OSC_RECV_PORT 3861

class ofApp : public ofBaseApp{

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

        ofxOscReceiver osc_recv;

        ofCamera cam;
//        ofEasyCam cam;
        ofVec3f cam_pos;
        ofVec3f cam_ang;

        ofxAssimpModelLoader cubes_model;

};
