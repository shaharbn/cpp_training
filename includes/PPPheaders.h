// PPPheaders.h - the same as PPP.h, but without modules.
// Use this with g++ / Clang (or any compiler where "import std;" doesn't work):
//
//   #include "PPPheaders.h"

#ifndef PPPHEADERS_H
#define PPPHEADERS_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <ranges>
#include <set>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define PPP_EXPORT
#include "PPP_support.h"

using namespace std;
using namespace PPP;

// macro hack so that vector, string and span are the range-checked versions:
#define vector Checked_vector
#define string Checked_string
#define span Checked_span

#endif