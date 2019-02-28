#ifndef LUKELUASOL_LUKELUASOL_HPP
#define LUKELUASOL_LUKELUASOL_HPP

#include <Luke/WindowSettings.hpp>
#include <sol/sol.hpp>

namespace lukeLuaSol
{

STICK_API void registerLuke(sol::state_view _lua, const stick::String & _namespace = "");
STICK_API void registerLuke(sol::state_view _lua, sol::table _tbl);

} // namespace lukeLuaSol

/* helpers to allow WindowSettings to be created from a table */
namespace sol
{
namespace stack
{

template <>
struct checker<luke::WindowSettings>
{
    template <typename Handler>
    static bool check(lua_State * L, int index, Handler && handler, record & tracking)
    {
        return sol::stack::check<sol::table>(L, index, handler, tracking);
    }
};

template <>
struct getter<luke::WindowSettings>
{
    static luke::WindowSettings get(lua_State * L, int index, record & tracking)
    {
        luke::WindowSettings ret;

        sol::table tbl = sol::stack::get<sol::table>(L, lua_absindex(L, index), tracking);

        sol::optional<bool> oResizeable = tbl["resizeable"];
        if (oResizeable)
            ret.setResizeable(oResizeable.value());

        sol::optional<bool> oDecorated = tbl["decorated"];
        if (oDecorated)
            ret.setDecorated(oDecorated.value());

        sol::optional<const char *> oTitle = tbl["title"];
        if (oTitle)
            ret.setTitle(oTitle.value());

        sol::optional<sol::table> oPos = tbl["position"];
        if (oPos)
            ret.setPosition(oPos.value()["x"], oPos.value()["y"]);

        sol::optional<sol::table> oSize = tbl["size"];
        if (oSize)
            ret.setSize(oSize.value()["width"], oSize.value()["height"]);

        sol::optional<luke::Display &> oDisplay = tbl["display"];
        if (oDisplay)
            ret.setDisplay(oDisplay.value());

        sol::optional<stick::UInt32> oSampleCount = tbl["sampleCount"];
        if (oSampleCount)
            ret.setSampleCount(oSampleCount.value());

        sol::optional<stick::UInt32> oColPrecision = tbl["colorPrecision"];
        if (oColPrecision)
            ret.setColorPrecision(oColPrecision.value());

        sol::optional<stick::UInt32> oAlphaPrecision = tbl["alphaPrecision"];
        if (oAlphaPrecision)
            ret.setAlphaPrecision(oAlphaPrecision.value());

        sol::optional<stick::UInt32> oStencilPrecision = tbl["stencilPrecision"];
        if (oStencilPrecision)
            ret.setStencilPrecision(oStencilPrecision.value());

        sol::optional<stick::UInt32> oDepthPrecision = tbl["depthPrecision"];
        if (oDepthPrecision)
            ret.setDepthPrecision(oDepthPrecision.value());

        return ret;
    }
};

} // namespace stack
} // namespace sol

#endif // LUKELUASOL_LUKELUASOL_HPP
