#include "levelable_interface.hpp"
// do .cpp
int levelable_interface::level() const {
    return calculate_level(experience());
}
