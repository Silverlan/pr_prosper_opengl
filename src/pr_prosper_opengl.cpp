// SPDX-FileCopyrightText: (c) 2020 Silverlan <opensource@pragma-engine.com>
// SPDX-License-Identifier: MIT

import pragma.prosper.opengl;

extern "C" {
PR_EXPORT bool initialize_render_api(const std::string &engineName, bool enableValidation, std::shared_ptr<prosper::IPrContext> &outContext, std::string &errMsg)
{
	outContext = prosper::GLContext::Create(engineName, enableValidation);
	return true;
}
};
