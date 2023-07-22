#include <frontend/components/topbar.hpp>

#include <nui/frontend/elements.hpp>
#include <nui/frontend/attributes.hpp>

namespace RegexGenerator
{
    // #####################################################################################################################
    struct Topbar::Implementation
    {
        // ...
    };
    // #####################################################################################################################
    Topbar::Topbar()
        : impl_(std::make_unique<Implementation>())
    {}
    //---------------------------------------------------------------------------------------------------------------------
    Topbar::Topbar(Topbar&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    Topbar& Topbar::operator=(Topbar&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    Topbar::~Topbar() = default;
    //---------------------------------------------------------------------------------------------------------------------
    Nui::ElementRenderer Topbar::render()
    {
        using namespace Nui::Elements;
        using namespace Nui::Attributes;
        using Nui::Elements::div; // because of the global div.

        // clang-format off
        return div{id = "Topbar"}(
            "Topbar"
        );
        // clang-format on
    }
    // #####################################################################################################################
}