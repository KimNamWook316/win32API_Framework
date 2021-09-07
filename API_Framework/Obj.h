#pragma once
class Obj {
public:
	explicit Obj();
	~Obj();
	
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC& hdc) = 0;
	virtual void Release() = 0;

	void SetPos(const float& _x, const float& _y) {
		mInfo.x = _x;
		mInfo.y = _y;
	}

	void Die() { mbDead = true; }

	const INFO& GetInfo() { return mInfo; }
	const RECT& GetRect() { return mRect; }

protected:
	void updateRect();

protected:
	INFO mInfo;
	RECT mRect;

	float mSpeed;

	bool mbDead;
};

