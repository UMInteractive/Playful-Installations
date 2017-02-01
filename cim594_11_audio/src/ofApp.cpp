#include "ofApp.h"

//this is a local function, so it doesn't need to be declared in the function. We use it with ofRemove

bool isDead( Particle &p ){
    if(p.a < 0) {
        return true;
    }
    else {
        return false;
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    soundStream.printDeviceList();
    ofBackground(0,0,0);
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;
    
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    myFont.load("led.ttf", 100);

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
    
    
    ofColor tmpColor = ofColor(255, 255, 255);
    Particle myParticle;
    float vx = ofRandom(-1,1);
    //the downward trajectory is going to depend on how loud our input is
    float vy = ofRandom(-1,1);
    myParticle.setInitialCondition(x,y,vx, vy);
    myParticle.color = tmpColor;
    myParticle.radius = loudness*100;
    // more interesting with diversity :)
    // uncomment this:
    myParticle.damping = ofRandom(0.01, 0.05);
    particles.push_back(myParticle);
}

//--------------------------------------------------------------
void ofApp::update(){
    //remove particles if life has gone past 0
    ofRemove(particles, isDead);
    x+=20;
    if(x > ofGetWidth()) {
        x = 0;
        y+= 20;
    }
    if (y > ofGetHeight()) {
        y = 0;
    }
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
    ofSetColor(0, 255, 127);
    float fontness = myFont.stringWidth("Hello")/2;
    myFont.drawString("Hello", ofGetWidth()/2 - fontness, ofGetHeight()/2);
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
