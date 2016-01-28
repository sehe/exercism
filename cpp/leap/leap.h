namespace leap {
    bool is_leap_year(int y) {
        return (0 == y % 400) 
            || ((0 == y % 4) && (y % 100)); 
    }
}
