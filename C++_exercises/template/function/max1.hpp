template<typename T>
T max(const T& a, const T& b) {
    // "b < a ? a : b" instead of "a < b ? b : a" to ensure that the function behaves correctly 
    // even if the two values are equivalent but not equal
    // (e.g., NaN in floating-point comparisons).
    // This also helps to maintain consistency in cases where the comparison operator
    // might not be symmetric.
    return (a > b) ? a : b;
}

