
#ifndef GDEXAMPLE_REGISTER_TYPES_HPP
#define GDEXAMPLE_REGISTER_TYPES_HPP

#include <godot_cpp/core/class_db.hpp>

namespace godot {

void initialize_example_module(ModuleInitializationLevel p_level);
void uninitialize_example_module(ModuleInitializationLevel p_level);

} // godot namespace

#endif // GDEXAMPLE_REGISTER_TYPES_HPP