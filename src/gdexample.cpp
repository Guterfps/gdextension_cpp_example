
#include <godot_cpp/core/class_db.hpp>

#include "gdexample.hpp"

namespace godot {

GDExample::GDExample() : 
m_time_passed(0.0), m_time_emit(0.0), m_amplitude(10.0), m_speed(1.0) {
}

GDExample::~GDExample() {

}

void GDExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_amplitude"), &GDExample::get_amplitude);
    ClassDB::bind_method(D_METHOD("set_amplitude", "amplitude"), 
                            &GDExample::set_amplitude);
    ClassDB::add_property("GDExample", 
                        PropertyInfo(Variant::FLOAT, "amplitude"),
                        "set_amplitude", "get_amplitude");

    ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), 
                            &GDExample::set_speed);
    ClassDB::add_property("GDExample", 
                        PropertyInfo(Variant::FLOAT, "speed",
                        PROPERTY_HINT_RANGE, "0,20,0.01"),
                        "set_speed", "get_speed");

    ADD_SIGNAL(MethodInfo("position_changed", 
                PropertyInfo(Variant::OBJECT, "node"), 
                PropertyInfo(Variant::VECTOR2, "new_pos")));

}

void GDExample::_process(double delta) {
    m_time_passed += m_speed * delta;

    Vector2 new_position = Vector2(m_amplitude + 
                            (m_amplitude * sin(m_time_passed * 2.0)),
                            m_amplitude + 
                            (m_amplitude * cos(m_time_passed * 1.5)));
    set_position(new_position);

    m_time_emit += delta;
    if (m_time_emit > 1.0) {
        emit_signal("position_changed", this, new_position);

        m_time_emit = 0.0;
    }
}

void GDExample::set_amplitude(const double& amplitude) {
    m_amplitude = amplitude;
}

double GDExample::get_amplitude() const {
    return m_amplitude;
}

void GDExample::set_speed(const double& speed) {
    m_speed = speed;
}

double GDExample::get_speed() const {
    return m_speed;
}


} // godot namespace