#include <frontend/components/bottom_panel.hpp>

#include <nui/frontend/elements.hpp>
#include <nui/frontend/attributes.hpp>

namespace RegexGenerator
{
    // #####################################################################################################################
    struct BottomPanel::Implementation
    {
        // ...
    };
    // #####################################################################################################################
    BottomPanel::BottomPanel()
        : impl_(std::make_unique<Implementation>())
    {}
    //---------------------------------------------------------------------------------------------------------------------
    BottomPanel::BottomPanel(BottomPanel&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    BottomPanel& BottomPanel::operator=(BottomPanel&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    BottomPanel::~BottomPanel() = default;
    //---------------------------------------------------------------------------------------------------------------------
    Nui::ElementRenderer BottomPanel::render()
    {
        using namespace Nui::Elements;
        using namespace Nui::Attributes;
        using Nui::Elements::div; // because of the global div.

        // clang-format off
        return div{id = "BottomPanel", reference.onMaterialize([](Nui::val element){
        })}(       
        );
        // clang-format on
    }
    // #####################################################################################################################
}