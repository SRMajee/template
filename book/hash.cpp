#include "cp_utils.h"

// ---------- UNIVERSAL HASH TEMPLATE ---------- //
struct HashCombine {
    template <typename T>
    inline void operator()(size_t &seed, const T &val) const noexcept {
        seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
};

struct StateHash {
    template <typename T>
    size_t operator()(const T &key) const noexcept {
        return hash_value(key);
    }

private:
    // For pair
    template <typename A, typename B>
    static size_t hash_value(const std::pair<A, B> &p) noexcept {
        size_t seed = 0;
        HashCombine{}(seed, p.first);
        HashCombine{}(seed, p.second);
        return seed;
    }

    // For tuple of arbitrary size
    template <typename... Args>
    static size_t hash_value(const std::tuple<Args...> &t) noexcept {
        return hash_tuple(t, std::index_sequence_for<Args...>{});
    }

    template <typename Tuple, size_t... I>
    static size_t hash_tuple(const Tuple &t, std::index_sequence<I...>) noexcept {
        size_t seed = 0;
        (HashCombine{}(seed, std::get<I>(t)), ...);
        return seed;
    }

    // For vector or container of hashable elements
    template <typename T>
    static size_t hash_value(const std::vector<T> &v) noexcept {
        size_t seed = v.size();
        for (const auto &x : v)
            HashCombine{}(seed, x);
        return seed;
    }

    // For simple scalar types
    template <typename T>
    static size_t hash_value(const T &x) noexcept {
        return std::hash<T>()(x);
    }
};
