#pragma once
#include <numeric>
#include "fightable_interface.hpp"


class character: public fightable_interface {

using attributes_map_type = fightable_interface::attributes_map_type

    attributes_map_type attributes_;
    int experience_;
public:
    character(attributes_map_type const &attrs, int experience = 0);

    int health() const;

    virtual int experience() const override;

    virtual attributes_map_type const &attributes() const override;

    virtual int overall_power() const override;
};
