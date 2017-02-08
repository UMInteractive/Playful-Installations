//
//  TimedSound.hpp
//  cim594_18_audioout
//
//  Created by Clay Ewing on 2/8/17.
//
//

#ifndef TimedSound_hpp
#define TimedSound_hpp

#include "ofMain.h"

class TimedSound{
    
public:
    
        
    TimedSound();
    virtual ~TimedSound(){};
    
    ofSoundPlayer *sound;
    
    ofVec2f a;
    ofVec2f b;
    float position;
    float timer;
    float timeBetweenPlays;
    void draw();
    void update();
    void setInitialConditions(int x, int y, float timeBetweenPlay);
    
protected:
private:
};

#endif /* TimedSound_hpp */
