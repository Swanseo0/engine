#ifndef EMBEDDER_FLUTTER_TIZEN_ENGINE_GROUP_H_
#define EMBEDDER_FLUTTER_TIZEN_ENGINE_GROUP_H_

#include "flutter/shell/platform/tizen/flutter_tizen_engine.h"

namespace flutter {

class FlutterTizenEngineGroup {
 public:
  static FlutterTizenEngineGroup& GetInstance() {
    static FlutterTizenEngineGroup instance;
    return instance;
  }

  FlutterTizenEngineGroup() {}

  FlutterTizenEngine* MakeEngineWithProject(
      const FlutterProjectBundle& project);

  int GetEngineCount();

  FlutterTizenEngine* GetEngineSpawner();

 private:
  std::vector<std::shared_ptr<FlutterTizenEngine>> engines_;
};

}  // namespace flutter

#endif
