#include "pch.h"
#include "MainGame.h"
#include "Player.h"
#include "Wall.h"

MainGame::MainGame() 
	:mPlayer(nullptr)
	,mWall(nullptr){
}

MainGame::~MainGame() {
	Release();
}

void MainGame::Initialize() {
	mHdc = GetDC(gHwnd);
	if (!mPlayer) {
		mPlayer = new Player;
		mPlayer->Initialize();
	}

	if (!mWall) {
		mWall = new Wall;
		mWall->Initialize();
	}

	static_cast<Player*>(mPlayer)->SetBullet(&mListBullet);
	static_cast<Wall*>(mWall)->SetBullet(&mListBullet);
}

void MainGame::Update() {
	mPlayer->Update();

	for (auto& pBullet : mListBullet) {
		pBullet->Update();
	}

	mWall->Update();
}

void MainGame::Render() {
	Rectangle(mHdc, -1, -1, WINCX, WINCY);
	mWall->Render(mHdc);
	mPlayer->Render(mHdc);

	for (auto& pBullet : mListBullet) {
		pBullet->Render(mHdc);
	}

}

void MainGame::Release() {
	SAFE_DELETE(mPlayer);

	std::for_each(mListBullet.begin(), mListBullet.end(), Safe_Delete<Obj*>);
	mListBullet.clear();

	SAFE_DELETE(mWall);

	ReleaseDC(gHwnd, mHdc);
}
