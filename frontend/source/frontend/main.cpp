#include <frontend/components/main_page.hpp>

#include <nui/core.hpp>
#include <nui/window.hpp>

#include <nui/frontend/dom/dom.hpp>

#include <nui/frontend/attributes.hpp>
#include <nui/frontend/elements.hpp>

extern "C" void frontendMain()
{
    using namespace RegexGenerator;

    thread_local MainPage mainPage;
    thread_local Nui::Dom::Dom dom;

    using namespace Nui::Elements;
    dom.setBody(body{}(mainPage.render()));
}

EMSCRIPTEN_BINDINGS(nui_example_frontend)
{
    emscripten::function("main", &frontendMain);
}
#include <nui/frontend/bindings.hpp>