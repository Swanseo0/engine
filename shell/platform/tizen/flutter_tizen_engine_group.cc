#include "flutter/shell/platform/tizen/flutter_tizen_engine_group.h"

namespace flutter {

FlutterTizenEngine* FlutterTizenEngineGroup::MakeEngineWithProject(
    const FlutterProjectBundle& project) {
  std::shared_ptr<FlutterTizenEngine> engine = nullptr;
  engine = std::make_shared<flutter::FlutterTizenEngine>(project);
  engine->SetEngineName(std::string("FlutterTizenEngine") +
                        std::to_string(engines_.size()));
  engine->SetRemoveCallback([&](std::string name) {
    for (size_t i = 0; i < engines_.size(); ++i) {
      if (engines_[i]->name() == name) {
        engines_.erase(engines_.begin() + i);
        return;
      }
    }
  });

  engines_.push_back(engine);

  return engine.get();
}

int FlutterTizenEngineGroup::GetEngineCount() {
  return engines_.size();
}

FlutterTizenEngine* FlutterTizenEngineGroup::GetEngineSpawner() {
  return engines_[0].get();
}

}  // namespace flutter