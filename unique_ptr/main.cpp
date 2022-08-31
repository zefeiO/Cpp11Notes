#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Entity {
public:
    Entity() {
        std::cout << "Created Entity!\n";
    }

    ~Entity() {
        std::cout << "Destroyed Entity!\n";
    }

    void print() {};
};

class Owner {
public:
    
    void take_entity(std::unique_ptr<Entity>& e) {
        ptr.swap(e);
    }

    void take_entity(std::unique_ptr<Entity>&& e) {
        entities.push_back(e);
    }

private:
    std::unique_ptr<Entity> ptr;
    std::vector<std::unique_ptr<Entity>> entities;
};

int main() {
    auto owner = Owner();
    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->print();
        owner.take_entity(entity);

        auto e = std::make_unique<Entity>();
        owner.take_entity(std::move(e));
        std::cout << e << '\n';
    }

    
    return 0;
}