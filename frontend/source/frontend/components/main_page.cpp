#include <frontend/components/main_page.hpp>
#include <frontend/components/main_content.hpp>
#include <frontend/components/sidebar.hpp>
#include <frontend/components/topbar.hpp>

#include <nui/frontend/elements.hpp>
#include <nui/frontend/attributes.hpp>

namespace RegexGenerator
{
    // #####################################################################################################################
    struct MainPage::Implementation
    {
        MainContent mainContent;
        Sidebar sidebar;
        Topbar topbar;
    };
    // #####################################################################################################################
    MainPage::MainPage()
        : impl_(std::make_unique<Implementation>())
    {}
    //---------------------------------------------------------------------------------------------------------------------
    MainPage::~MainPage() = default;
    //---------------------------------------------------------------------------------------------------------------------
    MainPage::MainPage(MainPage&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    MainPage& MainPage::operator=(MainPage&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    Nui::ElementRenderer MainPage::render()
    {
        using namespace Nui;
        using namespace Nui::Elements;
        using namespace Nui::Attributes;
        using Nui::Elements::div; // because of the global div.

        // clang-format off
        return div{id = "MainPage"}(
            impl_->topbar.render(),
            impl_->sidebar.render(),
            impl_->mainContent.render()
        );
        // clang-format on
    }
    // #####################################################################################################################
}