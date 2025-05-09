#include "Stronghold.h"
using namespace std;
ResourceManager::ResourceManager() {
    for (int i = 0; i < RESOURCE_TYPE_COUNT; i++) {
        resources[i] = Resource(static_cast<ResourceType>(i), 100.0);
    }
}
void ResourceManager::gather(ResourceType type, int a) {
    if (type >= 0 && type < RESOURCE_TYPE_COUNT) {
        resources[type].gather(a);
    }
}
void ResourceManager::consume(ResourceType type, int a) {
    if (type >= 0 && type < RESOURCE_TYPE_COUNT) {
        resources[type].consume(a);
    }
}
void ResourceManager::trade(ResourceType fromType, ResourceType toType, int a) {
    if (fromType >= 0 && fromType < RESOURCE_TYPE_COUNT && toType >= 0 && toType < RESOURCE_TYPE_COUNT) {
        resources[fromType].trade(a);
        resources[toType].gather(a);
    }
}
int ResourceManager::get(ResourceType type) const {
    if (type >= 0 && type < RESOURCE_TYPE_COUNT) {
        return resources[type].getAmount();
    }
    return 0;
}
void ResourceManager::update(Kingdom& kingdom) {
    for (int i = 0; i < RESOURCE_TYPE_COUNT; i++) {
        resources[i].update(kingdom);
    }
}