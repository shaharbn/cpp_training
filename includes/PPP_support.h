// PPP_support.h
//
// Support code for "Programming: Principles and Practice Using C++" (3rd edition).
// Same facilities (same names, same behavior) as Stroustrup's official PPP_support.h.
//
// Don't include this file directly:
//   - module version:  PPP.ixx includes it   (you write:  #include "PPP.h"  or  import PPP;)
//   - header version:  PPPheaders.h includes it (you write: #include "PPPheaders.h")
//
// PPP_EXPORT is "export" inside the module and nothing in the header version.

#ifndef PPP_EXPORT
#define PPP_EXPORT
#endif

namespace PPP {

    using Unicode = long;

    // ============================================================
    //  Range checking
    //  vector, string and span whose [] throws on a bad index
    //  (iterators are not checked)
    // ============================================================

    template<class T> concept Element = true;

    PPP_EXPORT template<Element T>
    class Checked_vector : public std::vector<T> {
    public:
        using std::vector<T>::vector;               // inherit all constructors

        T& operator[](std::size_t i)
        {
            return std::vector<T>::at(i);           // at() throws std::out_of_range
        }

        const T& operator[](std::size_t i) const
        {
            return std::vector<T>::at(i);
        }
    };

    PPP_EXPORT class Checked_string : public std::string {
    public:
        using std::string::string;                  // inherit all constructors
        Checked_string() = default;
        Checked_string(const std::string& s) : std::string(s) {}      // so a std::string result
        Checked_string(std::string&& s) : std::string(std::move(s)) {} // (e.g. from +) converts back

        char& operator[](std::size_t i)
        {
            return std::string::at(i);              // at() throws std::out_of_range
        }

        const char& operator[](std::size_t i) const
        {
            return std::string::at(i);
        }
    };

    PPP_EXPORT template<Element T>
    class Checked_span : public std::span<T> {
    public:
        using std::span<T>::span;                   // inherit all constructors

        T& operator[](std::size_t i) const          // span's [] is const (a span doesn't own its elements)
        {
            if (i >= this->size()) throw std::out_of_range("span range error");
            return std::span<T>::operator[](i);
        }
    };

    // let "span s = v;" / "span s {arr};" deduce the element type
    template<class T, std::size_t N>
    Checked_span(T (&)[N]) -> Checked_span<T>;

    template<class T, std::size_t N>
    Checked_span(std::array<T, N>&) -> Checked_span<T>;

    template<class T, std::size_t N>
    Checked_span(const std::array<T, N>&) -> Checked_span<const T>;

    template<class R>
    Checked_span(R&&) -> Checked_span<std::remove_reference_t<std::ranges::range_reference_t<R>>>;

    template<class It, class End>
    Checked_span(It, End) -> Checked_span<std::remove_reference_t<std::iter_reference_t<It>>>;

    // ============================================================
    //  Error handling
    // ============================================================

    PPP_EXPORT struct Exit : std::runtime_error {    // throw Exit{} to leave a program
        Exit() : std::runtime_error("Exit") {}
    };

    PPP_EXPORT inline void error(const std::string& s)   // error() simply disguises a throw
    {
        throw std::runtime_error(s);
    }

    PPP_EXPORT inline void error(const std::string& s, const std::string& s2)
    {
        error(s + s2);
    }

    PPP_EXPORT inline void error(const std::string& s, int i)
    {
        std::ostringstream os;
        os << s << ": " << i;
        error(os.str());
    }

    // expect(): take an action if an expected condition doesn't hold
    //   expect([&]{ return 0 < x; }, "x must be positive");

    PPP_EXPORT enum class Error_action { ignore, throwing, terminating, logging, error };

    PPP_EXPORT struct except_error : std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    PPP_EXPORT constexpr Error_action default_error_action = Error_action::error;

    PPP_EXPORT template<Error_action action = default_error_action, typename C>
    constexpr void expect(C cond, std::string mess)
    {
        if constexpr (action == Error_action::logging)
            if (!cond()) std::cerr << "expect() error: " << mess << '\n';
        if constexpr (action == Error_action::throwing)
            if (!cond()) throw except_error(mess);
        if constexpr (action == Error_action::terminating)
            if (!cond()) std::terminate();
        if constexpr (action == Error_action::error)
            if (!cond()) PPP::error(mess);
        // Error_action::ignore: do nothing
    }

    // ============================================================
    //  Narrowing conversions
    //    narrow_cast<T>(x)  unchecked: "I know this loses information"
    //    narrow<T>(x)       checked:   throws narrowing_error if the value changes
    // ============================================================

    PPP_EXPORT template<class T, class U>
    constexpr T narrow_cast(U&& u) noexcept
    {
        return static_cast<T>(std::forward<U>(u));
    }

    PPP_EXPORT struct narrowing_error : std::exception {
        const char* what() const noexcept override { return "narrowing_error"; }
    };

    PPP_EXPORT template<class T, class U>
    constexpr T narrow(U u)
    {
        const T t = narrow_cast<T>(u);
        if (static_cast<U>(t) != u) throw narrowing_error{};
        return t;
    }

    // ============================================================
    //  Random numbers
    // ============================================================

    PPP_EXPORT inline std::default_random_engine& get_rand()
    {
        static std::default_random_engine ran;
        return ran;
    }

    PPP_EXPORT inline void seed(int s) { get_rand().seed(s); }
    PPP_EXPORT inline void seed() { get_rand().seed(); }       // back to the default seed

    PPP_EXPORT inline int random_int(int min, int max)          // random int in [min:max]
    {
        return std::uniform_int_distribution<>{min, max}(get_rand());
    }

    PPP_EXPORT inline int random_int(int max)                   // random int in [0:max]
    {
        return random_int(0, max);
    }

    // ============================================================
    //  Type helpers
    // ============================================================

    PPP_EXPORT template<typename C>
    using Value_type = typename C::value_type;

    PPP_EXPORT template<typename C>
    using Iterator = typename C::iterator;

} // namespace PPP

// make std::min() and std::max() usable on systems (Windows) with min/max macros
#undef min
#undef max

// so Checked_string can be a key in unordered_map / unordered_set
template<>
struct std::hash<PPP::Checked_string> {
    std::size_t operator()(const PPP::Checked_string& s) const
    {
        return std::hash<std::string>()(s);
    }
};