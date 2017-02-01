#include "ofApp.h"

//this is a local function, so it doesn't need to be declared in the function. We use it with ofRemove

bool isDead( Particle &p ){
    
    if(p.life < 0) {
        return true;
    }
    else {
        return false;
    }
     
}

//--------------------------------------------------------------
void ofApp::setup(){
    soundStream.printDeviceList();
    
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;

    //set initial values for beat detection
    decayRate = 0.05;
    minimumThreshold = 0.1;
    threshold = minimumThreshold;
    //soundStream isn't going to listen directly to this sound we're loading.
    

    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    //set timer to current time
    timer = ofGetElapsedTimef() + 5;

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
    threshold = ofLerp(threshold, minimumThreshold, decayRate);
    if(loudness > threshold) {
        //when the timer reaches our limit, we let it go
        if(timer < ofGetElapsedTimef()) {
            //then we add 5 seconds to the existing time again
            timer = ofGetElapsedTimef() + 5;
            //times up, allow something to happen
            ofColor tmpColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
            Particle myParticle;
            float vx = ofRandom(-1,1);
            //the downward trajectory is going to depend on how loud our input is
            float vy = ofRandom(0,loudness*100);
            myParticle.setInitialCondition(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
            myParticle.color = tmpColor;
            // more interesting with diversity :)
            // uncomment this:
            myParticle.damping = ofRandom(0.01, 0.05);
            particles.push_back(myParticle);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //remove particles if life has gone past 0
    //this releases very few particles, so we'll kill this for now.

    //    ofRemove(particles, isDead);

    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].bounceOffWalls();
        particles[i].addDampingForce();
        particles[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//The loudness is a very small number, to see it, we're going to map it with a much larger number of the screen width
    ofSetColor(0, 0, 0);
    if(timer > ofGetElapsedTimef()) {
        ofDrawBitmapString("TIME REMAINING: " + ofToString(timer - ofGetElapsedTimef()), ofGetWidth()/2, ofGetHeight()/2);
    }
    else {
        ofDrawBitmapString("Make a sound to release a particle", ofGetWidth()/2, ofGetHeight()/2);
        
    }
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
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
