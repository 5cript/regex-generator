#include <frontend/components/main_content.hpp>
#include <frontend/components/bottom_panel.hpp>

#include <frontend/json.hpp>

#include <nui/frontend/utility/stabilize.hpp>
#include <nui/frontend/elements.hpp>
#include <nui/frontend/attributes.hpp>

namespace RegexGenerator
{
    // #####################################################################################################################
    struct MainContent::Implementation
    {
        Nui::StableElement editor;
        BottomPanel bottomPanel;
    };
    // #####################################################################################################################
    MainContent::MainContent()
        : impl_(std::make_unique<Implementation>())
    {}
    //---------------------------------------------------------------------------------------------------------------------
    MainContent::MainContent(MainContent&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    MainContent& MainContent::operator=(MainContent&&) = default;
    //---------------------------------------------------------------------------------------------------------------------
    MainContent::~MainContent() = default;
    //---------------------------------------------------------------------------------------------------------------------
    Nui::ElementRenderer MainContent::render()
    {
        using namespace Nui::Elements;
        using namespace Nui::Attributes;
        using Nui::Elements::div; // because of the global div.

        // clang-format off
        return div{id = "MainContent"}(
            div{id = "EditorFrame", reference.onMaterialize([](Nui::val element){
                Nui::val::global("makeResizeable")(element, Nui::val{5}, Nui::val{"bottom"});
            })}(
                stabilize(impl_->editor, div{id = "Editor", reference.onMaterialize([](Nui::val element){
                    Nui::val::global("createMonacoEditor")(element, js({
                        {"value", "function x() {\n  console.log(\"Hello world!\");\n}"},
                        {"language", "javascript"},
                        {"theme", "vs-dark"}
                    }));
                })}())
            ),
            impl_->bottomPanel.render()
        );
        // clang-format on
    }
    // #####################################################################################################################
}