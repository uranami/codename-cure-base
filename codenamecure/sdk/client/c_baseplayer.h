#pragma once

class c_baseplayer
{
public:
	int& m_fFlags()
	{
		return *(int*)((uintptr_t)this + 0x354);
	}

};