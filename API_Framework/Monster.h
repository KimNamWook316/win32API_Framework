#pragma once
#include "Obj.h"
class Monster : public Obj {
public:
	explicit Monster();
	~Monster();

	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC& hdc) override;
	virtual void Release() override;

	void SetDir(MONSTER::DIRECTION dir) { mDir = dir; }

private:
	MONSTER::DIRECTION mDir;
};

