#pragma once
#include"head.h"
template<class T>
class MapNode
{
public:
	void push(MapNode<T> *mapNode)
	{
		to_ptr.push_back(mapNode);
		mapNode->pull(this);
	}
	void pull(MapNode<T> *mapNode)
	{
		from_ptr.push_back(mapNode);
		mapNode->push(this);
	}
	T data;
	vector<MapNode*> from_ptr;
	vector<MapNode*> to_ptr;
};
