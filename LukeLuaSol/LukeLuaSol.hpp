#ifndef LUKELUASOL_LUKELUASOL_HPP
#define LUKELUASOL_LUKELUASOL_HPP

#include <Luke/Luke.hpp>
#include <StickLuaSol/StickLuaSol.hpp>

namespace lukeLuaSol
{

STICK_API void registerLuke(sol::state_view _lua, const stick::String & _namespace = "");
STICK_API void registerLuke(sol::state_view _lua, sol::table _tbl);

STICK_API void registerLuke(sol::state_view _lua, const stick::String & _namespace)
{
    registerLuke(_lua, stickLuaSol::ensureNamespaceTable(_lua, _lua.globals(), _namespace));
}

STICK_API void registerLuke(sol::state_view _lua, sol::table _tbl)
{
    using namespace luke;
    using namespace stick;

    sol::table tbl = _tbl;

    tbl.new_enum("KeyCode",
                 "A",
                 KeyCode::A,
                 "B",
                 KeyCode::B,
                 "C",
                 KeyCode::C,
                 "D",
                 KeyCode::D,
                 "E",
                 KeyCode::E,
                 "F",
                 KeyCode::F,
                 "G",
                 KeyCode::G,
                 "H",
                 KeyCode::H,
                 "I",
                 KeyCode::I,
                 "J",
                 KeyCode::J,
                 "K",
                 KeyCode::K,
                 "L",
                 KeyCode::L,
                 "M",
                 KeyCode::M,
                 "N",
                 KeyCode::N,
                 "O",
                 KeyCode::O,
                 "P",
                 KeyCode::P,
                 "Q",
                 KeyCode::Q,
                 "R",
                 KeyCode::R,
                 "S",
                 KeyCode::S,
                 "T",
                 KeyCode::T,
                 "U",
                 KeyCode::U,
                 "V",
                 KeyCode::V,
                 "W",
                 KeyCode::W,
                 "X",
                 KeyCode::X,
                 "Y",
                 KeyCode::Y,
                 "Z",
                 KeyCode::Z,
                 "One",
                 KeyCode::One,
                 "Two",
                 KeyCode::Two,
                 "Three",
                 KeyCode::Three,
                 "Four",
                 KeyCode::Four,
                 "Five",
                 KeyCode::Five,
                 "Six",
                 KeyCode::Six,
                 "Seven",
                 KeyCode::Seven,
                 "Eight",
                 KeyCode::Eight,
                 "Nine",
                 KeyCode::Nine,
                 "Return",
                 KeyCode::Return,
                 "Escape",
                 KeyCode::Escape,
                 "Delete",
                 KeyCode::Delete,
                 "Tab",
                 KeyCode::Tab,
                 "Space",
                 KeyCode::Space,
                 "Subtract",
                 KeyCode::Subtract,
                 "Equal",
                 KeyCode::Equal,
                 "LeftBracket",
                 KeyCode::LeftBracket,
                 "RightBracket",
                 KeyCode::RightBracket,
                 "Backslash",
                 KeyCode::Backslash,
                 "WorldOne",
                 KeyCode::WorldOne,
                 "Semicolon",
                 KeyCode::Semicolon,
                 "Apostrophe",
                 KeyCode::Apostrophe,
                 "GraveAccent",
                 KeyCode::GraveAccent,
                 "Comma",
                 KeyCode::Comma,
                 "Period",
                 KeyCode::Period,
                 "Slash",
                 KeyCode::Slash,
                 "CapsLock",
                 KeyCode::CapsLock,
                 "F1",
                 KeyCode::F1,
                 "F2",
                 KeyCode::F2,
                 "F3",
                 KeyCode::F3,
                 "F4",
                 KeyCode::F4,
                 "F5",
                 KeyCode::F5,
                 "F6",
                 KeyCode::F6,
                 "F7",
                 KeyCode::F7,
                 "F8",
                 KeyCode::F8,
                 "F9",
                 KeyCode::F9,
                 "F10",
                 KeyCode::F10,
                 "F11",
                 KeyCode::F11,
                 "F12",
                 KeyCode::F12,
                 "F13",
                 KeyCode::F13,
                 "F14",
                 KeyCode::F14,
                 "F15",
                 KeyCode::F15,
                 "F16",
                 KeyCode::F16,
                 "Caret",
                 KeyCode::Caret,
                 "LeftControl",
                 KeyCode::LeftControl,
                 "LeftShift",
                 KeyCode::LeftShift,
                 "LeftAlt",
                 KeyCode::LeftAlt,
                 "LeftCommand",
                 KeyCode::LeftCommand,
                 "RightControl",
                 KeyCode::RightControl,
                 "RightShift",
                 KeyCode::RightShift,
                 "RightAlt",
                 KeyCode::RightAlt,
                 "RightCommand",
                 KeyCode::RightCommand,
                 "Right",
                 KeyCode::Right,
                 "Left",
                 KeyCode::Left,
                 "Down",
                 KeyCode::Down,
                 "Up",
                 KeyCode::Up,
                 "Help",
                 KeyCode::Help,
                 "Mute",
                 KeyCode::Mute,
                 "VolumeUp",
                 KeyCode::VolumeUp,
                 "VolumeDown",
                 KeyCode::VolumeDown,
                 "KPDivide",
                 KeyCode::KPDivide,
                 "KPMultiply",
                 KeyCode::KPMultiply,
                 "KPSubtract",
                 KeyCode::KPSubtract,
                 "KPAdd",
                 KeyCode::KPAdd,
                 "KPReturn",
                 KeyCode::KPReturn,
                 "KPOne",
                 KeyCode::KPOne,
                 "KPTwo",
                 KeyCode::KPTwo,
                 "KPThree",
                 KeyCode::KPThree,
                 "KPFour",
                 KeyCode::KPFour,
                 "KPFive",
                 KeyCode::KPFive,
                 "KPSix",
                 KeyCode::KPSix,
                 "KPSeven",
                 KeyCode::KPSeven,
                 "KPEight",
                 KeyCode::KPEight,
                 "KPNine",
                 KeyCode::KPNine,
                 "KPZero",
                 KeyCode::KPZero,
                 "KPDecimal",
                 KeyCode::KPDecimal,
                 "KPEqual",
                 KeyCode::KPEqual,
                 "KPComma",
                 KeyCode::KPComma);

    tbl.new_usertype<Event>("Event",
                            "new",
                            sol::no_constructor,
                            "name",
                            &Event::name,
                            "eventTypeID",
                            &Event::eventTypeID,
                            "stopPropagation",
                            &Event::stopPropagation,
                            "propagationStopped",
                            &Event::propagationStopped);

    tbl.new_usertype<KeyEvent>("KeyEvent",
                               "new",
                               sol::no_constructor,
                               "key",
                               &KeyEvent::key,
                               "scancode",
                               &KeyEvent::scancode);

    tbl.new_usertype<KeyDownEvent>("KeyDownEvent",
                                   sol::base_classes,
                                   sol::bases<Event, KeyEvent>(),
                                   "new",
                                   sol::no_constructor,
                                   "isRepeat",
                                   &KeyDownEvent::isRepeat);

    tbl.new_usertype<KeyUpEvent>(
        "KeyUpEvent", sol::base_classes, sol::bases<Event, KeyEvent>(), "new", sol::no_constructor);

    tbl.new_enum("MouseButton",
                 "Left",
                 MouseButton::Left,
                 "Right",
                 MouseButton::Right,
                 "Middle",
                 MouseButton::Middle,
                 "Button3",
                 MouseButton::Button3,
                 "Button4",
                 MouseButton::Button4,
                 "Button5",
                 MouseButton::Button5,
                 "Button6",
                 MouseButton::Button6,
                 "Button7",
                 MouseButton::Button7,
                 "None",
                 MouseButton::None);

    tbl.new_enum("FullscreenMode",
                 "Borderless",
                 FullscreenMode::Borderless,
                 "Fullscreen",
                 FullscreenMode::Fullscreen);

    tbl.new_usertype<MouseState>("MouseState",
                                 "new",
                                 sol::no_constructor,
                                 "x",
                                 &MouseState::x,
                                 "y",
                                 &MouseState::y,
                                 "isButtonDown",
                                 &MouseState::isButtonDown,
                                 "buttonBitMask",
                                 &MouseState::buttonBitMask);

    tbl.new_usertype<MouseEvent>("MouseEvent",
                                 "new",
                                 sol::no_constructor,
                                 "x",
                                 &MouseEvent::x,
                                 "y",
                                 &MouseEvent::y,
                                 "button",
                                 &MouseEvent::button,
                                 "mouseState",
                                 &MouseEvent::mouseState);

    tbl.new_usertype<MouseScrollEvent>("MouseScrollEvent",
                                       sol::base_classes,
                                       sol::bases<Event, MouseEvent>(),
                                       "new",
                                       sol::no_constructor,
                                       "scollX",
                                       &MouseScrollEvent::scrollX,
                                       "scrollY",
                                       &MouseScrollEvent::scrollY);

    tbl.new_usertype<MouseMoveEvent>("MouseMoveEvent",
                                     sol::base_classes,
                                     sol::bases<Event, MouseEvent>(),
                                     "new",
                                     sol::no_constructor);

    tbl.new_usertype<MouseDownEvent>("MouseDownEvent",
                                     sol::base_classes,
                                     sol::bases<Event, MouseEvent>(),
                                     "new",
                                     sol::no_constructor);

    tbl.new_usertype<MouseUpEvent>("MouseUpEvent",
                                   sol::base_classes,
                                   sol::bases<Event, MouseEvent>(),
                                   "new",
                                   sol::no_constructor);

    tbl.new_usertype<DisplayMode>("DisplayMode",
                                  "new",
                                  sol::no_constructor,
                                  "width",
                                  &DisplayMode::width,
                                  "height",
                                  &DisplayMode::height,
                                  "redBits",
                                  &DisplayMode::redBits,
                                  "greenBits",
                                  &DisplayMode::greenBits,
                                  "blueBits",
                                  &DisplayMode::blueBits,
                                  "refreshRate",
                                  &DisplayMode::refreshRate);

    tbl.new_usertype<Display>("Display",
                              "new",
                              sol::no_constructor,
                              "setDisplayMode",
                              &Display::setDisplayMode,
                              "currentDisplayMode",
                              &Display::currentDisplayMode,
                              "findBestDisplayMode",
                              &Display::findBestDisplayMode,
                              "displayModes",
                              &Display::displayModes,
                              "isValidDisplayMode",
                              &Display::isValidDisplayMode,
                              "isValid",
                              &Display::isValid,
                              "x",
                              &Display::x,
                              "y",
                              &Display::y,
                              "mainDisplay",
                              &Display::mainDisplay,
                              "displays",
                              &Display::displays);

    // tbl.new_usertype<WindowSettings>("WindowSettings",
    //                                  sol::call_constructor,
    //                                  sol::constructors<WindowSettings()>(),
    //                                  "setResizeable",
    //                                  &WindowSettings::setResizeable,
    //                                  "setDecorated",
    //                                  &WindowSettings::setDecorated,
    //                                  "setTitle",
    //                                  &WindowSettings::setTitle,
    //                                  "setPosition",
    //                                  &WindowSettings::setPosition,
    //                                  "setSize",
    //                                  &WindowSettings::setSize,
    //                                  "setDisplay",
    //                                  &WindowSettings::setDisplay,
    //                                  "setSampleCount",
    //                                  &WindowSettings::setSampleCount,
    //                                  "setColorPrecision",
    //                                  &WindowSettings::setColorPrecision,
    //                                  "setAlphaPrecision",
    //                                  &WindowSettings::setAlphaPrecision,
    //                                  "setStencilPrecision",
    //                                  &WindowSettings::setStencilPrecision,
    //                                  "setDepthPrecision",
    //                                  &WindowSettings::setDepthPrecision,
    //                                  "isResizeable",
    //                                  &WindowSettings::isResizeable,
    //                                  "isDecorated",
    //                                  &WindowSettings::isDecorated,
    //                                  "display",
    //                                  &WindowSettings::display,
    //                                  "title",
    //                                  &WindowSettings::title,
    //                                  "x",
    //                                  &WindowSettings::x,
    //                                  "y",
    //                                  &WindowSettings::y,
    //                                  "width",
    //                                  &WindowSettings::width,
    //                                  "height",
    //                                  &WindowSettings::height,
    //                                  "sampleCount",
    //                                  &WindowSettings::sampleCount,
    //                                  "colorPrecision",
    //                                  &WindowSettings::colorPrecision,
    //                                  "alphaPrecision",
    //                                  &WindowSettings::alphaPrecision,
    //                                  "depthPrecision",
    //                                  &WindowSettings::depthPrecision,
    //                                  "stencilPrecision",
    //                                  &WindowSettings::stencilPrecision);

    // we specialize stick::EventForwarder on the lua side for luke input and window events so that
    // other classes that use those event types can derive from it.
    // @TODO: possibly add event filter stuff?
    // @TODO: Possibly move this to StickLuaSol and make another intermediate class for window/input events?
    tbl.new_usertype<EventForwarder>(
        "EventForwarder",
        "new",
        sol::no_constructor, // we don't allow direct construction for now
        "setEnabled",
        &EventForwarder::setEnabled,
        "isEnabled",
        &EventForwarder::isEnabled,
        "addForwarder",
        &EventForwarder::addForwarder,
        "removeForwarder",
        &EventForwarder::removeForwarder,
        "addMouseMoveCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const MouseMoveEvent & _evt) { _fn(_evt); });
        },
        "addMouseUpCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const MouseUpEvent & _evt) { _fn(_evt); });
        },
        "addMouseDownCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const MouseDownEvent & _evt) { _fn(_evt); });
        },
        "addKeyUpCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const KeyUpEvent & _evt) { _fn(_evt); });
        },
        "addKeyDownCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const KeyDownEvent & _evt) { _fn(_evt); });
        },
        "addWindowMoveCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const WindowMoveEvent & _evt) { _fn(_evt); });
        },
        "addWindowResizeCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const WindowResizeEvent & _evt) { _fn(_evt); });
        },
        "addWindowFocusCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const WindowFocusEvent & _evt) { _fn(_evt); });
        },
        "addWindowLostFocusCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const WindowLostFocusEvent & _evt) { _fn(_evt); });
        },
        "addWindowIconifyCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const WindowIconifyEvent & _evt) { _fn(_evt); });
        },
        "addWindowRestoreCallback",
        [](EventForwarder & _self, sol::function _fn) {
            return _self.addEventCallback([_fn](const WindowRestoreEvent & _evt) { _fn(_evt); });
        },
        "removeEventCallback",
        &EventForwarder::removeEventCallback);

    tbl.new_usertype<Window>(
        "Window",
        sol::call_constructor,
        sol::base_classes,
        sol::bases<EventForwarder>(),
        sol::factories([](const WindowSettings & _settings, sol::this_state _s) {
            sol::state_view L(_s);
            std::unique_ptr<Window> wnd(new Window);
            auto err = wnd->open(_settings);
            if (err)
                return sol::make_object(L, err);
            return sol::make_object(L, std::move(wnd));
        }),
        "close",
        &Window::close,
        "move",
        &Window::move,
        "moveToCenter",
        &Window::moveToCenter,
        "show",
        &Window::show,
        "hide",
        &Window::hide,
        "resize",
        &Window::resize,
        "maximize",
        &Window::maximize,
        "enableRenderContext",
        &Window::enableRenderContext,
        "enterFullscreen",
        sol::overload(
            [](Window & _self) { return _self.enterFullscreen(); },
            (Error(Window::*)(FullscreenMode, const Display &)) & Window::enterFullscreen,
            (Error(Window::*)(const DisplayMode &, const Display &)) & Window::enterFullscreen,
            (Error(Window::*)(Float32, Float32, const Display &)) & Window::enterFullscreen),
        "exitFullscreen",
        &Window::exitFullscreen,
        "setVerticalSync",
        &Window::setVerticalSync,
        "hideCursor",
        &Window::hideCursor,
        "showCursor",
        &Window::showCursor,
        "setTitle",
        &Window::setTitle,
        "swapBuffers",
        &Window::swapBuffers,
        "shouldClose",
        &Window::shouldClose,
        "isVisible",
        &Window::isVisible,
        "isFocussed",
        &Window::isFocussed,
        "isFullscreen",
        &Window::isFullscreen,
        "settings",
        &Window::settings,
        "isCursorVisible",
        &Window::isCursorVisible,
        "verticalSync",
        &Window::verticalSync,
        "title",
        &Window::title,
        "display",
        &Window::display,
        "width",
        &Window::width,
        "height",
        &Window::height,
        "widthInPixels",
        &Window::widthInPixels,
        "heightInPixels",
        &Window::heightInPixels,
        "x",
        &Window::x,
        "y",
        &Window::y);

    tbl.new_usertype<WindowMoveEvent>("WindowMoveEvent",
                                      sol::base_classes,
                                      sol::bases<Event>(),
                                      "new",
                                      sol::no_constructor,
                                      "x",
                                      &WindowMoveEvent::x,
                                      "y",
                                      &WindowMoveEvent::y);

    tbl.new_usertype<WindowResizeEvent>("WindowResizeEvent",
                                        sol::base_classes,
                                        sol::bases<Event>(),
                                        "new",
                                        sol::no_constructor,
                                        "width",
                                        &WindowResizeEvent::width,
                                        "height",
                                        &WindowResizeEvent::height);

    tbl.new_usertype<WindowFocusEvent>(
        "WindowFocusEvent", sol::base_classes, sol::bases<Event>(), "new", sol::no_constructor);

    tbl.new_usertype<WindowLostFocusEvent>(
        "WindowLostFocusEvent", sol::base_classes, sol::bases<Event>(), "new", sol::no_constructor);

    tbl.new_usertype<WindowIconifyEvent>(
        "WindowIconifyEvent", sol::base_classes, sol::bases<Event>(), "new", sol::no_constructor);

    tbl.new_usertype<WindowRestoreEvent>(
        "WindowRestoreEvent", sol::base_classes, sol::bases<Event>(), "new", sol::no_constructor);

    tbl.set_function("pollEvents", luke::pollEvents);
    tbl.set_function("setClipboardText", luke::setClipboardText);
    tbl.set_function("clipboardText", luke::clipboardText);
    tbl.set_function("hasClipboardText", luke::hasClipboardText);
    tbl.set_function("isKeyDown", luke::isKeyDown);
    tbl.set_function("mouseState", luke::mouseState);
    tbl.set_function("modifiers", luke::modifiers);
    tbl.set_function("modifier", luke::modifier);
}

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
        return sol::stack::check<sol::table>(L, index);
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
            ret.setPosition(oPos.value()[1], oPos.value()[2]);

        sol::optional<sol::table> oSize = tbl["size"];
        if (oSize)
            ret.setSize(oSize.value()[1], oSize.value()[2]);

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
