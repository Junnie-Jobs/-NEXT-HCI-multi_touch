//
//  Island.h
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 24..
//
//


#ifndef Island_h
#define Island_h
#include "ofMain.h"
class Island{
public:
    Island();
    ~Island();
    void setup(ofImage _img, string _name);
    void draw(ofImage img);
    void add(int x, int y);
    bool inside(int x, int y, string name);
    string getName();

public:
    string name;
    ofImage img;
    ofPoint pos;
};
#endif /* Island_h */
