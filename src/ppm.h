#ifndef PPM_H
#define PPM_H

#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "log.h"

namespace PPM_view
{

struct PPM_Header
{
    char type[3];
    uint16_t width;
    uint16_t height;
    uint16_t range;
};

struct PPM_Image
{
    PPM_Header header;
    uint8_t* data;
};

class PPM
{
  public:
    PPM(const std::string filepath);
    ~PPM();

    const uint16_t width() const
    {
        return m_image.get()->header.width;
    }

    const uint16_t height() const
    {
        return m_image.get()->header.height;
    }

    const uint8_t* data() const
    {
        return m_image.get()->data;
    }

  private:
    std::unique_ptr<PPM_Image> m_image;
    bool is_type_valid(const std::string type);
};

} // namespace PPM_view

#endif // !PPM_H
