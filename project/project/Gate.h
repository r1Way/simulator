#pragma once
#include"head.h"
#include"MapNode.h"
template<class T>
class Gate
{
public:
	vector<MapNode<T>*> in;
	vector<MapNode<T>*> out;
	vector<vector<int>> delay;

	virtual vector<int> figureValue()
	{
		vector<int> nextValue;
		//keep!!update
		return nextValue;
	}
	vector<bool> always()
	{
		vector<bool> temp(out.size(),false);
		vector<int> nextValue = figureValue();
		for (int i = 0; i < out.size(); i++)
		{
			if(out[i])
		}
	}
};
