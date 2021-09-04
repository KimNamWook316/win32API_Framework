#pragma once

class Obj;

class MainGame {
public:
	explicit MainGame();
	~MainGame();

	void Initialize();
	void Update();
	void Render();
	void Release();

private:
	HDC mHdc;
	Obj* mPlayer;
	Obj* mWall;

	std::list<Obj*> mListBullet;
};

