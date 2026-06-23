#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <Arduino.h>

enum SceneMode
{
    HOME_MODE,   // 回家模式：撤防、开灯、温控就绪
    AWAY_MODE,   // 离家模式：关灯、断电、设防
    NIGHT_MODE   // 睡眠模式：关灯、静音、保持安防
};

class SceneManager
{
public:
    void setScene(SceneMode mode);
    SceneMode getCurrentScene();
    bool undo();
    const char* getSceneName(SceneMode mode);

private:
    SceneMode _currentScene;
    SceneMode _previousScene;
    void enterScene(SceneMode mode);
};

#endif // SCENE_MANAGER_H
