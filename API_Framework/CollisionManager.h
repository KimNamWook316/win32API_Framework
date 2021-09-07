#pragma once

class Obj;

class CollisionManager {
public:
	CollisionManager();
	~CollisionManager();

	static void CollisionRect(const std::list<Obj*>& dest, const std::list<Obj*>& src);
	static void CollisionSphere(const std::list<Obj*>& dest, const std::list<Obj*>& src);

private:
	static bool checkSphere(const Obj* pDst, const Obj* pSrc);
};

