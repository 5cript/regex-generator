#pragma once

#include <nui/frontend/element_renderer.hpp>

#include <memory>

namespace RegexGenerator
{
    class BottomPanel
    {
      public:
        BottomPanel();
        ~BottomPanel();
        BottomPanel(const BottomPanel&) = delete;
        BottomPanel& operator=(const BottomPanel&) = delete;
        BottomPanel(BottomPanel&&);
        BottomPanel& operator=(BottomPanel&&);

        Nui::ElementRenderer render();

      private:
        struct Implementation;
        std::unique_ptr<Implementation> impl_;
    };
}