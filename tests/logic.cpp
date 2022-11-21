#include "test.h"
#include "./game_logic/game_logic.h"

class Logic : public Test {
    //GameLogic *logic;

 public:
    //Logic() : logic(1){}
    Logic() {
        //logic = new GameLogic(2);
    }

    void Keyboard(int key) override {
        switch (key) {
            case GLFW_KEY_A:
                //this->logic->move_player_left(0);
                break;

            case GLFW_KEY_D:
                //this->logic->move_player_right(0);
                break;

            case GLFW_KEY_W:
                //this->logic->jump_player(0);
                break;
        }
    }
/*
    void Step(Settings &settings) override {
        // g_debugDraw.DrawString(5, m_textLine,);
        int x = 0;
        Test::Step(settings);
    }
*/

    static Test *Create() {
        return new Logic;
    }
};

static int testIndex = RegisterTest("Local Test", "Game Logic", Logic::Create);
