#pragma once
#include <type_traits>

template <class ExplicitType = std::void_t<>>
struct ignore_argument {
    template <class T>
    struct ignore_inner {
        static inline T inner;
        constexpr operator T&() const { 
            static_assert(std::is_same<T, ExplicitType>::value || std::is_same<ExplicitType, void>::value, 
                "Types for ignore don't match");
            return inner; 
        }
    };

    template <class T>
    static inline ignore_inner<T> outer{};

    template <class T>
    constexpr operator T&() const {
        return outer<std::remove_const_t<T>>;
    }

    template <class T = ExplicitType> constexpr operator T() const { return operator T&(); }
    template <class T = ExplicitType> constexpr operator const T&() const { return operator T&(); }

};