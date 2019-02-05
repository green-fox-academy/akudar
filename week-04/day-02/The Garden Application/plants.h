#ifndef THE_GARDEN_APPLICATION_PLANTS_H
#define THE_GARDEN_APPLICATION_PLANTS_H


enum Color {
    YELLOW,
    BLUE,
    PURPLE,
    ORANGE
};

class Plants {

    double water;
    Color color;

public:
    Plants(Color setColor);
    double getWater() const;
    void setWater(double water);
    Color getColor() const;
    void setColor(Color color);
    virtual void watering(double amount);
};


#endif