// SPDX-FileCopyrightText: (c) 2020 Silverlan <opensource@pragma-engine.com>
// SPDX-License-Identifier: MIT

#include <prosper_opengl_definitions.hpp>
#include <gl_context.hpp>

#ifdef __linux__
#define DLLEXPORT __attribute__((visibility("default")))
#else
#define DLLEXPORT __declspec(dllexport)
#endif

extern "C" {
DLLEXPORT bool initialize_render_api(const std::string &engineName, bool enableValidation, std::shared_ptr<prosper::IPrContext> &outContext, std::string &errMsg)
{
	outContext = prosper::GLContext::Create(engineName, enableValidation);
	return true;
}
};
