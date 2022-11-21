#ifndef __CAR_H__
#define __CAR_H__

#include "box2d/b2_body.h"
#include "box2d/b2_circle_shape.h"
#include "box2d/b2_common.h"
#include "box2d/b2_math.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_types.h"
#include "box2d/b2_wheel_joint.h"
#include "box2d/box2d.h"
#include "box2d/b2_world.h"
#include "box2d/b2_fixture.h"
#include <cstdint>

enum {LEFT, RIGHT};

class Car {
 private:
    b2Body *chassis;
    b2Body *wheel1;
    b2Body *wheel2;
    b2WheelJoint *damper1;
    b2WheelJoint *damper2;
    bool orientation;
    uint8_t nitro_amount;
    void move();

 public:
    Car(b2World &world, const b2Vec2 &position);
    void moveLeft();
    void moveRight();
    void up();
    void brake();
    void jump();
    void boost();
    const b2Vec2 getPosition();
    const float getAngle();
    const uint8_t getOrientation();
    void set_nitro (bool on);

    // Refactorizar
    bool has_jumped;
    double time_elapsed;
    bool nitro;
    bool go_up;
};

#endif  // __CAR_H__
