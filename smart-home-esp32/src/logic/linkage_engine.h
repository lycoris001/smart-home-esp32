#ifndef LINKAGE_ENGINE_H
#define LINKAGE_ENGINE_H

#include <Arduino.h>
#include <functional>

struct Rule
{
    String name;
    std::function<bool()> condition;
    std::function<void()> action;
    bool enabled;
};

class LinkageEngine
{
public:
    Rule* addRule(const String& name, std::function<bool()> condition, std::function<void()> action);
    void removeRule(const String& name);
    void enableRule(const String& name);
    void disableRule(const String& name);
    void loop();

private:
    static const int MAX_RULES = 16;
    Rule _rules[MAX_RULES];
    int _ruleCount;
};

#endif // LINKAGE_ENGINE_H
