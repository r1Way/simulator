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

	virtual vector<int> figureValue() = 0
	{
		vector<int> nextValue;
		//keep!!update
		return nextValue;
	}
	vector<int> lastValue(Time * pre)
	{
		
		//update
	}
	vector<bool> always(Time * pre)//  �ж϶�Ӧout��value��lastValue������lastValueGate��...������ȣ��Ƿ����˸ı䣬����һ��bool����
	{
		vector<bool> temp(out.size(),false);
		vector<int> figure_Value = figureValue();
		vector<int> late_Value = lateValue(pre);
		for (int i = 0; i < out.size(); i++)
		{
			if (figure_Value[i] == late_Value[i])
			{
				temp[i] = true;
			}
			else
			{
				temp[i] = false;
			}
		}
		return temp;
	}
};
