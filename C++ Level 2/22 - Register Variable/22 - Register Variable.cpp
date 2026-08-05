// Register Variable
// Normally variables are stored in RAM memory
// The register keyword was a request to store the variable in a CPU register instead
// Like this
// register int UserNumber = 0;
// Accessing CPU registers is much faster than accessing RAM
// The compiler was free to ignore this request if no register was available
// Modern compilers optimize this automatically
// The register keyword became unnecessary
// It was deprecated in C++11 and removed in C++17