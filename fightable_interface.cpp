#include "fightable_interface.hpp"

//do .cpp
int fightable_interface::attribute_type::operator()(int level) const {
    return base_value + coefficient * level;
}

//do .cpp
int fightable_interface::attribute_value(attribute_type const &attr) const {
    return attr(level());
}

//do .cpp
boost::optional<fightable_interface::attribute_type> fightable_interface::attribute(std::string const &name) const {
    if(attributes().count(name))
        return attributes().at(name);
    return {};
}

//do .cpp
bool fightable_interface::beats(fightable_interface const &rhs) const {
    return overall_power() > rhs.overall_power();
}
