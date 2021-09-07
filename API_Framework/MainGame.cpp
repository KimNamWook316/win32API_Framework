#include "pch.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"

MainGame::MainGame() 
	:mPlayer(nullptr) 
	,mFps(0)
	,mTime(GetTickCount()){
}

MainGame::~MainGame() {
	Release();
}

void MainGame::Initialize() {
	mHdc = GetDC(gHwnd);
	
	Obj* pPlayer = AbFactory<Player>::Create();
	mListObj[OBJID::PLAYER].emplace_back(pPlayer);
	static_cast<Player*>(mListObj[OBJID::PLAYER].front())->SetBullet(&mListObj[OBJID::BULLET]);

	Obj* pMonster = AbFactory<Monster>::Create();
	static_cast<Monster*>(pMonster)->SetDir(MONSTER::LEFT);
	mListObj[OBJID::MONSTER].emplace_back(pMonster);
}

void MainGame::Update() {
	for (int i = 0; i < OBJID::END; ++i) {
		auto iter = mListObj[i].begin();
		while (iter != mListObj[i].end()) {
			int iEvent = ((*iter)->Update());

			if (OBJ_DEAD == iEvent) {
				SAFE_DELETE(*iter);
				iter = mListObj[i].erase(iter);
			} else {
				++iter;
			}
		}
	}
}

void MainGame::LateUpdate() {
	RECT rc = {};
	for (auto& pBullet : mListObj[OBJID::BULLET]) {
		for (auto& pMonster : mListObj[OBJID::MONSTER]) {
			if (IntersectRect(&rc, &(pBullet->GetRect()), &(pMonster->GetRect()))) {
				pBullet->Die();
				pMonster->Die();
			}
		}
	}

	for (int i = 0; i < OBJID::END; ++i) {
		for (auto& pObj : mListObj[i]) {
			pObj->LateUpdate();
		}
	}
}

void MainGame::Render() {
	Rectangle(mHdc, -1, -1, WINCX, WINCY);
	Rectangle(mHdc, 100, 100, WINCX - 100, WINCY - 100);
	
	for (int i = 0; i < OBJID::END; ++i) {
		for (auto& pObj : mListObj[i]) {
			pObj->Render(mHdc);
		}
	}

	++mFps;
	if (mTime + 1000 < GetTickCount()) {
		TCHAR szFPS[16] = L"";
		swprintf_s(szFPS, L"FPS : %d", mFps);
		SetWindowText(gHwnd, szFPS);
		mFps = 0;
		mTime = GetTickCount();
	}

#ifdef _DEBUG
	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L"Bullet : %d", mListObj[OBJID::BULLET].size());
	TextOut(mHdc, 50, 50, szBuff, lstrlen(szBuff));
#endif // _DEBUG

}

void MainGame::Release() {

	for (int i = 0; i < OBJID::END; ++i) {
		for_each(mListObj[i].begin(), mListObj[i].end(), Safe_Delete<Obj*>);
		mListObj[i].clear();
	}

	ReleaseDC(gHwnd, mHdc);
}
