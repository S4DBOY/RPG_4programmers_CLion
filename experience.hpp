#pragma once
#include <cassert>
#include <cmath>
#include <random>

int calculate_level(int experience);
//zostaje w .hpp
template<typename RNG>
int random_experience_in_range(int min_lvl, int max_lvl, RNG &rng) {
    return calculate_level_experience(
        std::uniform_int_distribution<int>(min_lvl, max_lvl)(rng)
    );
