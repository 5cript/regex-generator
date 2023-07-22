#pragma once

#include <nui/frontend/element_renderer.hpp>

#include <memory>

namespace RegexGenerator
{
    class Sidebar
    {
      public:
        Sidebar();
        ~Sidebar();
        Sidebar(const Sidebar&) = delete;
        Sidebar& operator=(const Sidebar&) = delete;
        Sidebar(Sidebar&&);
        Sidebar& operator=(Sidebar&&);

        Nui::ElementRenderer render();

      private:
        struct Implementation;
        std::unique_ptr<Implementation> impl_;
    };
}