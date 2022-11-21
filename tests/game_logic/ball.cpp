#include "ball.h"


Ball::Ball(b2World &world, float x, float y) {
    b2CircleShape circle;
    circle.m_radius = BALL_RADIUS;

    b2BodyDef ball_def;
    ball_def.type = b2_dynamicBody;
    ball_def.position.Set(x, y);

    b2FixtureDef ball_fd;
    ball_fd.shape = &circle;
    ball_fd.density = 0.5f;
    ball_fd.friction = 0.3f;
    ball_fd.restitution = 0.9f;
    ball_fd.restitutionThreshold = 1.0f;
    ball_fd.filter.categoryBits = BALL_BITS;
    ball_fd.filter.maskBits = CAR_BITS | SCENARIO_BITS;

    this->ball = world.CreateBody(&ball_def);
    this->ball->CreateFixture(&ball_fd);
}

const b2Vec2 Ball::getPosition() {
    return this->ball->GetPosition();
}

const float Ball::getAngle() {
    return this->ball->GetAngle();
}
