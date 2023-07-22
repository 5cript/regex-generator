#pragma once

#include <nlohmann/json.hpp>
#include <nui/frontend/api/json.hpp>

namespace RegexGenerator
{
    auto js(nlohmann::json const& json)
    {
        return Nui::JSON::parse(json.dump());
    }
}