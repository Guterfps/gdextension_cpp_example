
#ifndef GDEXAMPLE_HPP
#define GDEXAMPLE_HPP

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDExample : public Sprite2D {
    GDCLASS(GDExample, Sprite2D)

    public:
        GDExample();
        ~GDExample();

        void _process(double delta) override;

    protected:
        static void _bind_methods();

    private:
        double m_time_passed;
};

} // godot namespace

#endif // GDEXAMPLE_HPP