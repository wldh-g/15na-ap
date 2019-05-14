// Widh Jio
// core.hpp

#include "15na.hpp"
#include "csi.hpp"
#include "ws.hpp"

#ifndef IRONA_CORE
#define IRONA_CORE

namespace core
{

void procFlagOption(std::string);
void procShortFlagOption(std::string);
void procDataOption(std::string, std::string);
void procShortDataOption(std::string, std::string);

} // namespace core

#endif
