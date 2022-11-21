#include <box2d/b2_body.h>
#include <box2d/b2_circle_shape.h>
#include <box2d/b2_common.h>
#include <box2d/b2_math.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_wheel_joint.h>
#include <box2d/box2d.h>
#include <box2d/b2_world.h>
#include <box2d/b2_fixture.h>

#include "../../Rocket-League-sideswipe/game_logic/car.h"

Car::Car(b2World &world, const b2Vec2 &position) {
    float x = position.x, y = position.y;
    {
        b2BodyDef chassis_def;
        chassis_def.type = b2_dynamicBody;
        chassis_def.position.Set(x, y + 1.0f);


        b2PolygonShape chassis_shape;
        b2Vec2 vertices[6];
        vertices[0].Set(1.5f, -0.5f);
        vertices[1].Set(1.5f, 0.2f);
        vertices[2].Set(0.5f, 0.9f);
        vertices[3].Set(-0.5f, 0.9f);
        vertices[4].Set(-1.5f, 0.2f);
        vertices[5].Set(-1.5f, -0.5f);
        chassis_shape.Set(vertices, 6);

        b2FixtureDef chassis_fd;
        chassis_fd.density = 1.0f;
        chassis_fd.friction = 0.3f;
        chassis_fd.shape = &chassis_shape;

        this->chassis = world.CreateBody(&chassis_def);
        this->chassis->CreateFixture(&chassis_fd);
    }

    {
        b2CircleShape circle;
        circle.m_radius = 0.4f;

        b2FixtureDef wheel_fd;
        wheel_fd.shape = &circle;
        wheel_fd.density = 1.0f;
        wheel_fd.friction = 0.9f;
        wheel_fd.restitution = 0.1f;

        b2BodyDef wheel_def;
        wheel_def.type = b2_dynamicBody;
        wheel_def.position.Set(x - 1.0f, y + 0.35f);

        wheel1 = world.CreateBody(&wheel_def);
        wheel1->CreateFixture(&wheel_fd);

        wheel_def.position.Set(x + 1.0f, y + 0.35f);
        wheel2 = world.CreateBody(&wheel_def);
        wheel2->CreateFixture(&wheel_fd);
    }

    {
        b2WheelJointDef joint_def;
        b2Vec2 axis(0.0f, 1.0f);

        float mass1 = this->wheel1->GetMass();
        float mass2 = this->wheel2->GetMass();

        float hertz = 40.0f;
        float damping_ratio = 1.7f;
        float omega = 2.0f * b2_pi * hertz;

#define TRANSLATION 0.25f

        joint_def.Initialize(this->chassis, this->wheel1, this->wheel1->GetPosition(), axis);
        joint_def.motorSpeed = 0.0f;
        joint_def.maxMotorTorque = 20.0f;
        joint_def.enableMotor = true;
        joint_def.stiffness = mass1 * omega * omega;
        joint_def.damping = 2.0f * mass1 * damping_ratio * omega;
        joint_def.lowerTranslation = -TRANSLATION;
        joint_def.upperTranslation = TRANSLATION;
        joint_def.enableLimit = true;
        this->damper1 = (b2WheelJoint *)world.CreateJoint(&joint_def);

        joint_def.Initialize(this->chassis, this->wheel2, this->wheel2->GetPosition(), axis);
        joint_def.motorSpeed = 0.0f;
        joint_def.maxMotorTorque = 20.0f;
        joint_def.enableMotor = true;
        joint_def.stiffness = mass1 * omega * omega;
        joint_def.damping = 2.0f * mass1 * damping_ratio * omega;
        joint_def.lowerTranslation = -TRANSLATION;
        joint_def.upperTranslation = TRANSLATION;
        joint_def.enableLimit = true;
        this->damper2 = (b2WheelJoint *)world.CreateJoint(&joint_def);
    }
}

b2Vec2 Car::getPosition() {
    return chassis->GetPosition();
}

void Car::jump() {
    //this->chassis->ApplyLinearImpulseToCenter(b2Vec2(0.0f,50.0f), true);
    this->wheel1->ApplyLinearImpulseToCenter(b2Vec2(0.0f,20.0f), true);
    this->wheel2->ApplyLinearImpulseToCenter(b2Vec2(0.0f,20.0f), true);
}

void Car::moveLeft() {
    this->damper1->SetMotorSpeed(-50.0f);
    this->damper2->SetMotorSpeed(-50.0f);
}

void Car::moveRight() {
    this->damper1->SetMotorSpeed(50.0f);
    this->damper2->SetMotorSpeed(50.0f);
}

void Car::brake() {
    this->damper1->SetMotorSpeed(0.0f);
    this->damper2->SetMotorSpeed(0.0f);
}
