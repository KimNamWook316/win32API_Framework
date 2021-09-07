#include "pch.h"
#include "Mouse.h"

Mouse::Mouse() {
}

Mouse::~Mouse() {
	Release();
}

void Mouse::Initialize() {
	mInfo.cX = 50.f;
	mInfo.cY = 50.f;
}

int Mouse::Update() {
	if (mbDead) {
		return OBJ_DEAD;
	}

	POINT pt = {};
	GetCursorPos(&pt); // 전체 화면 기준으로 가져온다.
	ScreenToClient(gHwnd, &pt);
	ShowCursor(false);
	mInfo.x = (float)pt.x;
	mInfo.y = (float)pt.y;

	updateRect();

	return OBJ_NOEVENT;
}

void Mouse::LateUpdate() {
}

void Mouse::Render(HDC& hdc) {
	Ellipse(hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void Mouse::Release() {
}
