#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

namespace {
    bool g_immortalEnabled = false;

    void setImmortal(bool enabled) {
        g_immortalEnabled = enabled;

        Mod::get()->setSettingValue(
            "immortalEnabled",
            enabled
        );

        log::info(
            "Immortal Mode: {}",
            enabled ? "ON" : "OFF"
        );
    }
}

$on_mod(Loaded) {
    g_immortalEnabled =
        Mod::get()->getSettingValue<bool>(
            "immortalEnabled"
        );

    listenForSettingChanges<bool>(
        "immortalEnabled",
        +[](bool enabled) {
            setImmortal(enabled);
        }
    );
}

class $modify(ImmortalPlayLayer, PlayLayer) {
    void destroyPlayer(
        PlayerObject* player,
        GameObject* object
    ) {
        if (g_immortalEnabled) {
            return;
        }

        PlayLayer::destroyPlayer(player, object);
    }
};
