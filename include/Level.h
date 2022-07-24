#pragma once
class Level
{
public:
	Level();
	~Level();

	void Draw();

private:

	int xLineStep;
	int yLineStep;

	void Generate();
	void Init();
};

