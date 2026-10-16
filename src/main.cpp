
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(ImmortalPlayLayer, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        // Test mode: prevent normal player death.
        // This version is always enabled.
        (void)player;
        (void)object;
    }
};
