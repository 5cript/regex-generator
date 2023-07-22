#pragma once

#include <nui/frontend/element_renderer.hpp>

#include <memory>

namespace RegexGenerator
{
    class Topbar
    {
      public:
        Topbar();
        ~Topbar();
        Topbar(const Topbar&) = delete;
        Topbar& operator=(const Topbar&) = delete;
        Topbar(Topbar&&);
        Topbar& operator=(Topbar&&);

        Nui::ElementRenderer render();

      private:
        struct Implementation;
        std::unique_ptr<Implementation> impl_;
    };
}