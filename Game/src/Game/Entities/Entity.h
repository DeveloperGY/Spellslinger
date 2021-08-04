#pragma once

namespace gm
{
	namespace en
	{
		// Game Entity Test
		class Entity
		{
		private:

		public:
			// Creates Entity
			Entity();
			// Destroys Entitiy
			virtual ~Entity();

			// Activates Entity
			virtual void activate() = 0;
		};
	}
}