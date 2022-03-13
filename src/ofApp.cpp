#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    osc_recv.setup(OSC_RECV_PORT);

    cubes_model.loadModel("cubes.obj");
    cubes_model.setRotation(0, 180, 1, 0, 0);
    cubes_model.setScaleNormalization(false);
    cubes_model.setScale(.01, .01, .01);

}

//--------------------------------------------------------------
void ofApp::update(){

    while(osc_recv.hasWaitingMessages()){
        ofxOscMessage m;
        osc_recv.getNextMessage(m);
        if (m.getAddress() == "/cam/0"){
            cam_pos.x = m.getArgAsFloat(0);
            cam_pos.y = m.getArgAsFloat(1);
            cam_pos.z = m.getArgAsFloat(2);
            cam_ang.x = m.getArgAsFloat(3);
            cam_ang.y = m.getArgAsFloat(4);
            cam_ang.z = m.getArgAsFloat(5);
        }
        cout << m << endl;
    }

    cam.setPosition(cam_pos);
    cam.setOrientation(cam_ang);

}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    ofDrawGrid(10, 20, true);

    ofSetColor(255);

    cubes_model.setPosition(cubes_model.getSceneCenter().x * .01, 0, cubes_model.getSceneCenter().z * .01);
    cubes_model.drawWireframe();

    cam.end();

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
