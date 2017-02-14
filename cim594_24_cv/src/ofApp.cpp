#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 320;
    camHeight = 240;
    
    cam.setup(camWidth, camHeight);
    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
    
    bLearnBakground = true;
    threshold = 80;

}

//--------------------------------------------------------------
void ofApp::update(){
    bool bNewFrame = false;
    
    cam.update();
    bNewFrame = cam.isFrameNew();
    int contourCount = 0;
    if (bNewFrame){
        
        colorImg.setFromPixels(cam.getPixels());
        
        grayImage = colorImg;
        if (bLearnBakground == true){
            grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
            bLearnBakground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well....
        contourCount = contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);	// find holes
    }
    
    if(contourCount > 0) {
        timer = ofGetElapsedTimef() + 5;
        motionTimerRadius = 50;
        cout << "motion detected" << endl;
        bLearnBakground = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw the incoming, the grayscale, the bg and the thresholded difference
    ofSetHexColor(0xffffff);
    colorImg.draw(20,20);
    grayImage.draw(360,20);
    grayBg.draw(20,280);
    grayDiff.draw(360,280);
    motionTimerRadius -= .3f;
    if(timer > ofGetElapsedTimef()) {
        ofSetColor(0, 255, 0);
        ofDrawCircle(720, 280, motionTimerRadius);
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    bLearnBakground = true;

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
