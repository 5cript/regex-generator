#pragma once

#include <nui/frontend/element_renderer.hpp>

#include <memory>

namespace RegexGenerator
{
    class MainContent
    {
      public:
        MainContent();
        ~MainContent();
        MainContent(const MainContent&) = delete;
        MainContent& operator=(const MainContent&) = delete;
        MainContent(MainContent&&);
        MainContent& operator=(MainContent&&);

        Nui::ElementRenderer render();

      private:
        struct Implementation;
        std::unique_ptr<Implementation> impl_;
    };
}