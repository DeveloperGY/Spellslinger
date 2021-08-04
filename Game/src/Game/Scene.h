#pragma once

#include <vector>
#include "Entities/Entity.h"

namespace gm
{
	class Scene
	{
	private:
		std::vector<gm::en::Entity> entities;

	public:
		Scene();
		virtual ~Scene();
	};
}