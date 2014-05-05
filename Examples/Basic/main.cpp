#include<stdio.h>
#include "../../Engine/Include/World.hpp"
#include "../../Engine/Include/Scene.hpp"
#include "../../Engine/Include/Entity.hpp"
#include "../../Engine/Include/EntityManager.hpp"
#include "../../Engine/Include/SystemManager.hpp"
#include "../../Engine/Include/Component.hpp"
#include "../../Engine/Include/System.hpp"

using namespace Panther;

class system1 : public Panther::System
{
public:
  system1(){};
  ~system1(){};
  
  void process(){
    printf("hello from system");
  }
};

int main() {
  	Panther::World* world = new Panther::World();
  	Panther::Scene* scene = new Panther::Scene("TestScene");

  
  	world->addScene(scene);
  	
  	Entity* entity0 = scene->getEntityManager()->createEntity();


  	printf("Entity0: %i\n", entity0->getEntityId());
  	Entity* entity = scene->createEntity();

  	printf("Entity: %i\n", entity->getEntityId());

    system1* sys = new system1();

    scene->addSystem(sys);

  	world->process();
	return 1;
}

