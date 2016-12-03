#pragma once
#include "experience.hpp"

struct levelable_interface {
    virtual ~levelable_interface() = default;
    virtual int experience() const = 0;

    int level() const;
};
