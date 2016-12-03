#include "character.hpp"
#include "character_spawning.hpp"

#include <iostream>

auto characters_descs() {
    return characters_factory {{
        { "rat", characters_factory::character_desc {
            character::attributes_map_type {
                { "health", character::attribute_type{20, 3} },
                { "strength", character::attribute_type{3, 1} }
            },
            /*min*/1, /*max*/10
        }},

        { "lizard", characters_factory::character_desc {
            character::attributes_map_type {
                { "health", character::attribute_type{30, 3} },
                { "strength", character::attribute_type{5, 1} }
            },
            /*min*/3, /*max*/15
        }}
    }};
}

int main() {
    using namespace std;
    std::default_random_engine generator;

    auto factory = characters_descs();
    auto spawn = characters_spawner(factory);

    string characters[] = {
        "rat", "lizard"
    };
    for(size_t i = 0; i < 20; ++i) {
        for(auto ch_name: characters) {
            auto character = *spawn(ch_name, generator);
            cout << "character\'s class name:  " << ch_name << endl;
            cout << "character experience:    " << character->experience() << endl;
            cout << "character level:         " << character->level() << endl;
            cout << "character health:        " << character->health() << endl;
            cout << "character overall power: " << character->overall_power() << endl;
            cout << endl;
        }
    }
    return 0;
}
