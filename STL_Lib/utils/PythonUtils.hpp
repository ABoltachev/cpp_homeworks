#ifndef COLLECTIONS_PYTHONUTILS_HPP
#define COLLECTIONS_PYTHONUTILS_HPP

template <typename T>
class [[maybe_unused]] Range {

private:
    struct end_range {
        T end;
    };

    struct begin_range {
        T begin, step;

        begin_range& operator++() {
            begin += step;
            return *this;
        }

        bool operator!=(const end_range& end_range) const {
            return (step < 0) ? begin > end_range.end : begin < end_range.end;
        }

        const T& operator*() const {
            return begin;
        }

    };

    begin_range _begin;
    end_range _end;

public:
    explicit Range(T _end_)
    : _begin{0, 1}, _end{_end_} {}

    explicit Range(T _begin_, T _end_, T _step_ = 1)
    : _begin {_begin_, _step_}, _end {_end_} {};

    auto& begin() const {
        return _begin;
    }

    auto& end() const {
        return _end;
    }
};
#endif //COLLECTIONS_PYTHONUTILS_HPP