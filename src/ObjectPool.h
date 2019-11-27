#pragma once
#include "Entity.h"
#include <list>

//objectpool for entities
struct ObjectPool
{
private:
	std::list<Entity*> openSlots = std::list<Entity*>();

public:
	std::list<Entity*> list;
	std::list<Entity*> removeList;

	ObjectPool() {};
	~ObjectPool() {
		while (openSlots.size())
		{
			Entity* obj = openSlots.front();
			openSlots.pop_front();
			delete obj;
		}
		while (list.size())
		{
			Entity* obj = list.front();
			list.pop_front();
			delete obj;
		}
	};

	Entity* getResource(Entity* entity)
	{
		if (openSlots.empty())
		{
			list.push_back(entity);
			return entity;
		}
		else
		{
 			entity = openSlots.front();
			openSlots.pop_front();

			std::cout << "reusing: open slots: " << openSlots.size() << std::endl;
			return entity;
		}
	} 

	void returnResource(Entity* entity)
	{
		removeList.push_back(entity);

		openSlots.push_back(entity);
	}
};
