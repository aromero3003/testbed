#include "draw.h"
#include "test.h"
#include <box2d/b2_body.h>
#include <box2d/b2_math.h>


class HelloWorld : public Test {
    private:
        b2Body *body;
 public:
    HelloWorld() {
        m_world->SetGravity(b2Vec2(0.0f, -10.0f));
        float xcoor[4] = {-50.0f, 50.0f, 50.0f, -50.0f };
        float ycoor[4] = {0.0f, 0.0f, 40.0f, 40.0f};
        for (int i = 0; i < 4; i++) {
            b2BodyDef bodyDef;
            b2Body *ground = m_world->CreateBody(&bodyDef);

            b2EdgeShape shape;
            shape.SetTwoSided(b2Vec2(xcoor[i], ycoor[i]), b2Vec2(xcoor[(i+1)%4], ycoor[(i+1)%4]));

            b2FixtureDef fixtureDef;
            fixtureDef.shape = &shape;
            fixtureDef.restitutionThreshold = 1.0f;
            ground->CreateFixture(&fixtureDef);

        }



        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(0.0f, 10.0f);
        b2Body *body = m_world->CreateBody(&bodyDef);

        b2CircleShape shape;
        shape.m_radius = 1.5f;

        b2PolygonShape dynamicBox;
        //dynamicBox.SetAsBox(1.0f, 1.0f);
        b2Vec2 vertices[8];
            vertices[0].Set(-1.5f, -0.5f + 4);
              vertices[1].Set(1.5f, -0.5f + 4);
              vertices[2].Set(1.5f, 0.0f + 4);
              vertices[3].Set(0.0f, 0.9f + 4);
              vertices[4].Set(-1.15f, 0.9f + 4);
              vertices[5].Set(-1.5f, 0.2f + 4);
              dynamicBox.Set(vertices, 6);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        //fixtureDef.restitution = 0.7f;
        //fixtureDef.restitutionThreshold = 5.0f;
        //fixtureDef.friction = 0.3f;

        body->CreateFixture(&fixtureDef);
    }
	void Step(Settings& settings) override
	{
        b2Vec2 v = body->GetWorldVector(body->get)
        g_debugDraw.DrawString(10, m_textLine, "center of mass %f %f", this->body->GetPosition().x, this->body->GetPosition().y);
		m_textLine += m_textIncrement;

		Test::Step(settings);
	}


    static Test *Create() {
        return new HelloWorld;
    }
};

static int testIndex = RegisterTest("Local Test", "Hello b2World by Alan", HelloWorld::Create);
