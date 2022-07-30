#pragma once

#include <iostream>


#ifdef _DEBUG

#define DBG_MSG(x) (std::cout << #x << " = " << x << std::endl)

#endif //_DEBUG

typedef enum E_keys
{
	eNONE = 0,
	eSPACE,
	eUP,
	eDOWN,
	eLEFT,
	eRIGHT,
	eESC,
	eSHIFT,
	eCTRL
};
