#pragma once

// dll import export macro
#ifdef BUILD_DLL
#define CAS_API __declspec(dllexport)
#else
#define CAS_API __declspec(dllimport)
#endif