#ifndef __PR_PROSPER_OPENGL_HPP__
#define __PR_PROSPER_OPENGL_HPP__

#ifdef MODULE_SERVER
	#include "pragma/iserver.h"
	#define IState iserver
	#pragma comment(lib,"IServer.lib")
#else
	#include "pragma/iclient.h"
	#define IState iclient
	#pragma comment(lib,"IClient.lib")
#endif

#endif