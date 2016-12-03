#pragma once
#include <unordered_map>
#include <boost/optional.hpp>
#include "levelable_interface.hpp"

struct fightable_interface: public levelable_interface {
    struct attribute_type {
        int base_value = 0;
        int coefficient = 0;
        int operator()(int level) const;
    };

    using attributes_map_type = std::unordered_map<std::string, attribute_type>;

    virtual ~fightable_interface() = default;

    virtual attributes_map_type const &attributes() const = 0;

    int attribute_value(attribute_type const &attr) const;

    boost::optional<attribute_type> attribute(std::string const &name) const;

    virtual int overall_power() const = 0;

    virtual bool beats(fightable_interface const &rhs) const;
};
