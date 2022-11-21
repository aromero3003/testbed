#include "test.h"

class BodyTest : public Test {
 public:
    BodyTest() {

    }

    static Test *Create() {
        return new BodyTest;
    }

};

static int testIndex = RegisterTest("Local Test", "Hello b2World by Alan", HelloWorld::Create);
