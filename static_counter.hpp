template<int N>
struct Flag { friend constexpr int setFlag(Flag<N>); };

template<int N>
struct Writer
{
    friend constexpr int setFlag(Flag<N>) { return 0; }
};

template<int N>
constexpr int reader(float, Flag<N>) { return N; }

template<int N, int = setFlag(Flag<N>{})>
constexpr int reader(int, Flag<N>, int value = reader(0, Flag<N + 1>{}))
{
    return value;
}

template<int N = reader(0, Flag<0>{}), int = sizeof(Writer<N>) >
constexpr int next() { return N; }

