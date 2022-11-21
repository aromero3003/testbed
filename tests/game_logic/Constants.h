#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

// WORLD
#define GRAVITY 10.0f

// Recommended iterations for constraint resolver
#define VELOCITY_ITERATIONS 8
#define POSITION_ITERATIONS 3

#define TIME_STEP 1.0f/120.f




// Scenario
#define SCENARIO_HEIGHT 30
#define SCENARIO_HALF_WIDTH 20
#define SCENARIO_WIDTH SCENARIO_HALF_WIDTH * 2
#define SCENARIO_BORDERS 12
#define SCENARIO_BITS 0x2

// Ball
#define BALL_RADIUS 1.0f
#define BALL_BITS 0x4

// Car
#define CAR_BITS 0x1

#endif
