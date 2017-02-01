#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    soundStream.printDeviceList();
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;
    
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    //RMS Algorithm. Get loudness of input.
    
    float rms = 0.0;
    int numCounted = 0;
    for (int i = 0; i < bufferSize; i++) {
        float leftSample = input[i * 2] * .5;
        float rightSample = input[i * 2 + 1] * .5;
        rms += leftSample * leftSample;
        rms += rightSample * rightSample;
        numCounted += 2;
    }
    
    rms /= (float)numCounted;
    rms = sqrt(rms);
    loudness = rms;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//The loudness is a very small number, to see it, we're going to map it with a much larger number of the screen width
    float radius = ofMap(loudness, 0, 1, 0, ofGetWidth());
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
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
