namespace negicco {

enum class Color {
    Red,
    Yellow,
    Blue,
};

///@brief Hello, this is enum.
enum class Animal {
    Dog = 42,  //< This is a dog.
    Cat = 100, //< This is a cat.
    Fish = 3,  //< This is a fish.
};

/**
@brief C-style enum definition.
@details This is detail comment.
*/
enum CStyleEnum {
    One,
    Two,
    Three
};

enum class UnsignedCharEnum : unsigned char {
    ///@brief Hello one!
    One = 1,
    ///@brief Good morning two!!
    Two = 2,
    ///@brief Hi three!!!
    Three = 3,
};

namespace Fire {
    struct Ninja {
        enum class Buki {
            Shuriken,
            Katana,
            Makibishi,
        };
    };
} // namespace Buki

} // namespace negicco
