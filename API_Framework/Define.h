#pragma once

#define WINCX 800
#define WINCY 600

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }