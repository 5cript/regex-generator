#include <frontend/components/sidebar.hpp>

#include <nui/frontend/elements.hpp>
#include <nui/frontend/attributes.hpp>
#include <nui/frontend/extensions/make_resizeable.hpp>

namespace RegexGenerator
{
    // #####################################################################################################################
    struct Sidebar::Implementation
    {
        // ...
    };
    // #####################################################################################################################
    Sidebar::Sidebar()
        : impl_(std::make_unique<Implementation>())
    {}
    //---------------------------------------------------------------------------------------------------------------------
    Sidebar::Sidebar(Sidebar&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    Sidebar& Sidebar::operator=(Sidebar&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    Sidebar::~Sidebar() = default;
    //---------------------------------------------------------------------------------------------------------------------
    Nui::ElementRenderer Sidebar::render()
    {
        using namespace Nui::Elements;
        using namespace Nui::Attributes;
        using Nui::Elements::div; // because of the global div.

        // clang-format off
        return div{id = "Sidebar", reference.onMaterialize([](Nui::val const& val){
            Nui::makeResizeable(val, Nui::ResizeableEdge::Right);
        })}(
            // Sidebar content div, necessary for the resizeable bar to work.
            div{id = "SidebarContent"}("Sidebar")            
        );
        // clang-format on
    }
    // #####################################################################################################################
}