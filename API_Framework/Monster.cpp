#include "pch.h"
#include "Monster.h"

Monster::Monster() {
}

Monster::~Monster() {
    Release();
}

void Monster::Initialize() {
    mInfo.cX = 100.f;
    mInfo.cY = 100.f;

    mSpeed = 5.f;
}

int Monster::Update() {
    if (mbDead) {
        return OBJ_DEAD;
    }

    switch (mDir) {
    case MONSTER::LEFT:
        mInfo.x -= mSpeed;
        break;
    case MONSTER::RIGHT:
        mInfo.x += mSpeed;
        break;
    default:
        break;
    }

    updateRect();
    return OBJ_NOEVENT;
}

void Monster::LateUpdate() {
    if (100 >= mRect.left || WINCX - 100 < mRect.right) {
        if (MONSTER::LEFT == mDir) {
            mDir = MONSTER::RIGHT;
        }
        else if (MONSTER::RIGHT == mDir) {
            mDir = MONSTER::LEFT;
        }
    }
}

void Monster::Render(HDC& hdc) {
    Rectangle(hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void Monster::Release() {
}
