class Turtle {
    void drawHead() {}
    virtual void drawShell() {}
    void drawFeet() {}
    public:
        void draw() {
            drawHead();
            drawShell();
            drawFeet();
        }
};

class RedTurtle : public Turtle {
    void drawShell() override {
        // draw red shell
    }
};

class GreenTurtle : public Turtle {
    void drawShell() override {
        // draw green shell
    }
};