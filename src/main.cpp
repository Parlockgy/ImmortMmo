
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(ImmortalPlayLayer, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        bool immortal = Mod::get()->getSettingValue<bool>(
            "immortalEnabled"
        );

        if (immortal) {
            return;
        }

        PlayLayer::destroyPlayer(player, object);
    }
};
