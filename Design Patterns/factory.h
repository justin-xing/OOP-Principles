class Enemy {
    public:
        virtual int getDamage() const = 0;    
        virtual ~Enemy();
};

class Turtle : public Enemy {
    public:
        int getDamage() const override {
            return 2;
        }
};

class Bullet : public Enemy {
    public:
        int getDamage() const override {
            return 3;
        }
};

class Level {
    public:
        virtual Enemy * createEnemy() = 0; // factory method: a method to create Enemy objects
};

class Easy : public Level {
    public:
        Enemy * createEnemy() override {
            // creates mostly turtles
        }
};

class Hard : public Level {
    public:
        Enemy * createEnemy() override {
            // creates mostly bullets
        }
};