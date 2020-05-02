#pragma once
#include <Windows.h>
#include <memory>
#include <Psapi.h>
#include <chrono>
#include <thread>

namespace tools
{
	uintptr_t findpattern(const char* szModule, const char* szSignature);
}