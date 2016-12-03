#include <numeric>
#include "character.hpp"

//do .cpp
character::character(attributes_map_type const &attrs, int experience):
    attributes_(attrs),
    experience_(experience)
{}

//do .cpp
int character::health() const {
    return attribute_value(attribute("health").value_or(attribute_type{}));
}

//do .cpp
int character::experience() const
{ return experience_; }

//do .cpp
character::attributes_map_type const &character::attributes() const{
    return attributes_;
}

//do .cpp
int character::overall_power() const {
    auto sum = std::accumulate(std::begin(attributes()), std::end(attributes()), 0, [this](auto acc, auto &&pair) {
        return acc + attribute_value(pair.second);
    });
    auto h = health();
    return h *(sum - h);
}
