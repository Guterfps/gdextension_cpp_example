
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
        
        void set_amplitude(const double& amplitude);
        double get_amplitude() const;
        void set_speed(const double& speed);
        double get_speed() const;

    protected:
        static void _bind_methods();

    private:
        double m_time_passed;
        double m_time_emit;
        double m_amplitude;
        double m_speed;
};

} // godot namespace

#endif // GDEXAMPLE_HPP