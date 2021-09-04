#pragma once

template <typename T>
void Safe_Delete(T& dst) {
	if (dst) {
		delete dst;
		dst = nullptr;
	}
}