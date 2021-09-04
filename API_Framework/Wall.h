#pragma once
#include "Obj.h"
class Wall : public Obj {
public:
	explicit Wall();
	virtual ~Wall();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC& hdc) override;
	virtual void Release() override;

	void SetBullet(std::list<Obj*>* pBullet) { mPBullet = pBullet; }

private:
	void checkBulletCollide();

private:
	std::list<Obj*>* mPBullet;
};

