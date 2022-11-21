#ifndef __CAR_HANDLER_H__
#define __CAR_HANDLER_H__

#include "box2d/b2_math.h"
#include "box2d/b2_world.h"
#include "car.h"

class CarHandler {
 private:
    Car car;


 public:
    CarHandler (b2World &world, b2Vec2 position);
    bool has_jumped;

};

#endif  //  __CAR_HANDLER_H__
