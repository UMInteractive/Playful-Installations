#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(12345);
    x = ofGetWidth()/2;
    y = ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
    //This is going to look for just the accelerometer data
    
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
            if(m.getAddress() == "/mrmr/accelerometerX/33/Clays-6"){

                x = m.getArgAsInt(0);
            
            }
            if(m.getAddress() == "/mrmr/accelerometerY/33/Clays-6"){
                
                y = m.getArgAsInt(0);
                
            }

        }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(x, y, 50);
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
