

#include "tga_reader.h"


#include "TgaReader.h"
#include "Image.h"

#include <string.h>
#include <fstream>


Image* TgaReader::Load(const char* szFilename)
{
    return TgaReader::LoadFile(szFilename);
}


Image* TgaReader::LoadFile(const char* szFilename)
{
    Image*      pImage = NULL;
    IMAGE_TYPE  type = IMAGE_NULL;

    FILE* file = fopen(szFilename, "rb");
    if (file) {
        int size;
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        fseek(file, 0, SEEK_SET);

        unsigned char* buffer = (unsigned char*)tgaMalloc(size);
        fread(buffer, 1, size, file);
        fclose(file);

        int* pixels = tgaRead(buffer, TGA_READER_ABGR);
        int width = tgaGetWidth(buffer);
        int height = tgaGetHeight(buffer);

        if (pixels) {
            pImage = new Image(width, height, IMAGE_ABGRUCHAR);
            memcpy(pImage->GetImageDataPtr(), pixels, width * height * 4);
            tgaFree(pixels);
        }
        tgaFree(buffer);
    }

    return pImage;
}
