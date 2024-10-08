#pragma once

class IApplication
{
public:
	virtual ~IApplication() = default;
	bool virtual Initialize() = 0;
	void virtual Run() = 0;
	void virtual Stop() = 0;
};