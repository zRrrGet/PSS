#ifndef ACCESSLEVEL_H
#define ACCESSLEVEL_H

class AccessLevel
{
public:
    enum Level{                        // types of levels of access
      no_level, green, yellow, red
    };
private:
    Level level;
    void setLevel(const Level &value);
public:
    AccessLevel(Level l);
    Level getLevel() const;
};

#endif // ACCESSLEVEL_H
