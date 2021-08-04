#pragma once

#include <vector>
#include "Entities/Entity.h"

namespace gm
{
	class Scene
	{
	private:
		std::vector<gm::en::Entity> entities;
		char* _name = NULL;

	public:
		Scene();
		virtual ~Scene();

		// Getters

		// Returns the Scene Name
		char* getName();

		// Setters

		// Sets the Scene Name
		void setName(char*);
		// Sets the Scene Name
		void setName(const char*);
	};
}