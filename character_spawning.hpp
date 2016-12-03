#pragma once
#include <memory>
#include <functional>
#include "character.hpp"

struct characters_factory {
    struct character_desc {
        character::attributes_map_type attrs = {};
        int min_lvl = 1, max_lvl = 1;
    };
    using character_class_name = std::string;
    using character_descs_map = std::unordered_map<character_class_name, character_desc>;

    character_descs_map characters_descs;
};

class characters_spawner {
    characters_factory const &factory;
public:
    using character_class_name = characters_factory::character_class_name const &;
    using character_ptr_type = std::unique_ptr<character>;
    using optional_character_ptr_type = std::optional<character_ptr_type>;

    characters_spawner(characters_factory const &factory);

    template<typename RNG>
    optional_character_ptr_type spawn(character_class_name name, RNG &rng) const {
        if(!factory.characters_descs.count(name)) {
            return {};
        }
        auto &desc = factory.characters_descs.at(name);
        int experience = random_experience_in_range(desc.min_lvl, desc.max_lvl, rng);

        return character_ptr_type { new character(desc.attrs, experience) };
    }

    template<typename RNG>
    auto operator()(character_class_name name, RNG &rng) const {
        return spawn(name, rng);
    }
};
