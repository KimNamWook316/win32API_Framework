#pragma once
#include "Obj.h"
class Player : public Obj{
public:
	explicit Player();
	virtual ~Player();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC& hdc) override;
	virtual void Release() override;

	void SetBullet(std::list<Obj*>* pBullet) { mPBullet = pBullet; }

private:
	Obj* createBullet(DIRECTION dir);

private:
	std::list<Obj*>* mPBullet;
};