#pragma once
#include "Entity.h"

class UIIcon : public Entity
{
public:
	UIIcon() {}
	~UIIcon(){}
	UIIcon(GameDataRef data, const std::string& fileName, const std::string& keyName);
};

