#pragma once

class Obj;

class MainGame {
public:
	explicit MainGame();
	~MainGame();

	void Initialize();
	void Update();
	void LateUpdate();
	void Render();
	void Release();

private:
	HDC mHdc;
	Obj* mPlayer;
	
	std::list<Obj*> mListObj[OBJID::END];

	int mFps;
	DWORD mTime;

};

