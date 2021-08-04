#include "Scene.h"

gm::Scene::Scene()
{
	return;
}

gm::Scene::~Scene()
{
	return;
}

// Getters

char* gm::Scene::getName()
{
	return this->_name;
}

// Setters

void gm::Scene::setName(char* name)
{
	this->_name = name;
}

void gm::Scene::setName(const char* name)
{
	this->_name = (char*)name;
}