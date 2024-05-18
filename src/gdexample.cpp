
#include <godot_cpp/core/class_db.hpp>

#include "gdexample.hpp"

namespace godot {

void GDExample::_bind_methods() {
}

GDExample::GDExample() : m_time_passed(0.0) {

}

GDExample::~GDExample() {

}

void GDExample::_process(double delta) {
    m_time_passed += delta;

    Vector2 new_position = Vector2(10.0 + (10.0 * sin(m_time_passed * 2.0)),
                            10.0 + (10.0 * cos(m_time_passed * 1.5)));
    set_position(new_position);
}


} // godot namespace