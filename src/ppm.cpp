#include "ppm.h"

namespace PPM_view
{

PPM::PPM(const std::string filepath)
{
    // Open file
    std::ifstream file(filepath, std::ios::binary);

    if (!file.is_open())
    {
        std::cout << "Error opening file: " << std::strerror(errno) << std::endl;
        std::exit(1);
    }

    PPM_Header header{};

    file.getline(header.type, 3);

    if (!is_type_valid(header.type))
    {
        std::cout << "Invalid file type provided." << std::endl;
        std::exit(1);
    }

    file >> header.width >> header.height >> header.range;

    PPM_VIEW_DEBUG_LOG("Image header: width %d height %d range %d", header.width, header.height, header.range)

    PPM_Image image{};

    image.header = header;
    image.data = new uint8_t[header.width * header.height * 3];

    file.get(); // Skip whitespace

    file.read(reinterpret_cast<char*>(image.data), sizeof(uint8_t) * header.width * header.height * 3);

    m_image = std::make_unique<PPM_Image>(image);

    file.close();
}

bool PPM::is_type_valid(const std::string type)
{
    if (type.empty())
        return false;

    if (type.length() != 2)
        return false;

    if (type[0] != 'P' && type[0] != 'p')
        return false;

    if (type[1] != '3' && type[1] != '6')
        return false;

    return true;
}

PPM::~PPM()
{
    if (m_image != nullptr)
    {
        delete[] m_image.get()->data;
    }
}

} // namespace PPM_view
