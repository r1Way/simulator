#pragma once
class Gate;
class Element
{
public:
	int value;
	Gate *gate;

	Element(int value=0)
	{
		this->value = value;
	}
	void setValue(int value)
	{
		this->value = value;
	}
	int getValue()
	{
		return this->value;
	}
};
