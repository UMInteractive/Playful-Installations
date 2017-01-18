//
//  ball.h
//  cim594_01_classes
//
//  Created by Clay Ewing on 1/13/17.
//
//

#ifndef ball_h
#define ball_h

#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework
class Ball {
    
public: // place public functions or variables declarations here
    
    // methods, equivalent to specific functions of your class objects
    void setup();	// setup method, use this to setup your object's initial state
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing

    // variables
    float x;        // position
    float y;
    float speedY;   // speed and direction
    float speedX;
    int diameter;        // size
    ofColor color;  // color using ofColor type

    Ball();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
private: // place private functions or variables declarations here

}; // don't forget the semicolon!
#endif /* ball_h */
