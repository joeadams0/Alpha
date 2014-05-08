#include<stdio.h>
#include "World.hpp"
#include "Scene.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "Component.hpp"
#include "EntitySystem.hpp"
#include "EntityComposition.hpp"
#include <iostream>
#include <string>
#include "boost/variant.hpp"

using namespace Panther;


class Comp : public Component{
public:
  Comp(){};
  ~Comp(){};

  void hello(){
    std::cout << "hello from comp" << std::endl;
  }
};

class system1 : public Panther::EntitySystem
{
public:
  system1(){};
  ~system1(){};

  virtual void awake(){
    EntitySystem::awake();

    EntityComposition* comp = new EntityComposition();

    comp->all<Comp>();

    setEntityComposition(comp);
  }
  
  void process(){
    Panther::EntitySystem::process();

    Comp* component = new Comp();
    Entity* ent = getScene()->createEntity();

    ent->addComponent(component);

  }
};



int main() {

    Panther::World::setFps(3);
    Panther::World* world = Panther::World::getInstance();
    Panther::Scene* scene = new Panther::Scene("TestScene");

  
    world->addScene(scene);

    system1* sys = new system1();

    scene->addSystem(sys);


    world->process();
    world->start();
  return 1;
}

